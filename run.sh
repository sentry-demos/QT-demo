#!/bin/bash

Make clean 
Make
cd build
Make
cp Sentry-qt5-demo ../bin
cd ..
make upload_debug_files
./bin/Sentry-qt5-demo
