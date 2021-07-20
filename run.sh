#!/bin/bash

Make clean 
mkdir bin
Make
cd build
# builds qt application demo 
Make
# adds exec to bin file
cp Sentry-qt5-demo ../bin
cd ..
# setup suspect commit
make setup_release
# uploads debug files
make upload_debug_files
# runs exec
./bin/Sentry-qt5-demo
