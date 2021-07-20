SENTRY_ORG=testorg-az
SENTRY_PROJECT=qt5-demo
VERSION ?= $(shell sentry-cli releases propose-version)
CMAKE=cmake

all: bin
.PHONY: all prereqs sentry-makefile sentry-makefile setup_release create_release associate_commits upload_debug_files clean clean_db

bin: prereqs
	$(CMAKE) -B build -D CMAKE_BUILD_TYPE=DEBUG
	$(CMAKE) --build build

prereqs: bin/libsentry.dylib bin/crashpad_handler

bin/libsentry.dylib: sentry-makefile
	$(CMAKE) --build sentry-native/build --parallel --target sentry
	cp sentry-native/build/libsentry.dylib bin
	cp -R sentry-native/build/libsentry.dylib.dSYM bin

bin/crashpad_handler: sentry-makefile
	$(CMAKE) --build sentry-native/build --parallel --target crashpad_handler
	cp sentry-native/build/crashpad_build/handler/crashpad_handler bin
	cp -R sentry-native/build/crashpad_build/handler/crashpad_handler.dSYM bin

sentry-makefile: sentry-native/build/Makefile

sentry-native/build/Makefile:
	$(CMAKE) -B sentry-native/build -DSENTRY_INTEGRATION_QT=YES -DSENTRY_BACKEND=crashpad -DCMAKE_BUILD_TYPE=RelWithDebInfo sentry-native
	$(CMAKE) --build sentry-native/build --config RelWithDebInfo --parallel 
	$(CMAKE) --install sentry-native/build --prefix sentry-native/install

# SENTRYY
setup_release: create_release associate_commits
create_release:
	sentry-cli releases -o $(SENTRY_ORG) new -p $(SENTRY_PROJECT) $(VERSION)

associate_commits:
	sentry-cli releases -o $(SENTRY_ORG) -p $(SENTRY_PROJECT) set-commits $(VERSION) --auto

upload_debug_files:
	sentry-cli upload-dif --org testorg-az --project $(SENTRY_PROJECT) --wait --include-sources bin/

clean:
	rm -rf ./bin
	rm -rf ./build
	rm -rf ./sentry-db
