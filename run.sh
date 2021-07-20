#!/bin/bash

make clean
# creates bin directory 
mkdir bin
# make all
make
# copies exec to bin directory
cp build/Sentry-qt5-demo /bin
# setup suspect commit
make setup_release
# uploads debug files
make upload_debug_files
# runs exec
./bin/Sentry-qt5-demo
