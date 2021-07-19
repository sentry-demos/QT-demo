SENTRY_ORG=testorg-az
SENTRY_PROJECT=qt5-demo
VERSION ?= $(shell sentry-cli releases propose-version)
CMAKE=cmake

all: sentry-native/build/Makefile
.PHONY: all prereqs sentry-makefile sentry-makefile setup_release create_release associate_commits upload_debug_files clean clean_db

build/bin: prereqs build/bin
	$(CMAKE) -B build -D CMAKE_BUILD_TYPE=DEBUG

prereqs: build/bin /libsentry.dylib build/bin/crashpad_handler

build/bin/libsentry.dylib: sentry-makefile
	$(CMAKE) --build sentry-native/build --parallel --target sentry
	cp sentry-native/build/libsentry.dylib build/bin
	cp -R sentry-native/build/libsentry.dylib.dSYM build/bin

build/bin/crashpad_handler: sentry-makefile
	$(CMAKE) --build sentry-native/build --parallel --target crashpad_handler
	cp sentry-native/build/crashpad_build/handler/crashpad_handler build/bin
	cp -R sentry-native/build/crashpad_build/handler/crashpad_handler.dSYM build/bin

sentry-makefile: sentry-native/build/Makefile

sentry-native/build/Makefile:
	$(CMAKE) -B sentry-native/build -DSENTRY_INTEGRATION_QT=YES -DSENTRY_BACKEND=crashpad -DCMAKE_BUILD_TYPE=RelWithDebInfo
	$(CMAKE) --build sentry-native/build --config RelWithDebInfo --parallel
	$(CMAKE) --install sentry-native/build --prefix install


# SENTRYY
setup_release: create_release associate_commits
create_release:
	sentry-cli releases -o $(SENTRY_ORG) new -p $(SENTRY_PROJECT) $(VERSION)

 associate_commits:
 	sentry-cli releases -o $(SENTRY_ORG) -p $(SENTRY_PROJECT) set-commits $(VERSION) --auto

upload_debug_files:
	sentry-cli upload-dif --org testorg-az --project $(SENTRY_PROJECT) --wait --include-sources bin/

clean:
	rm -rf ./bin/exampl*
	rm -rf ./bin/crash*
	rm -rf ./bin/libsent*
	rm -rf ./build
	rm -rf ./sentry-db
