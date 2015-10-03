#!/usr/bin/env sh
echo "########################################################################"
echo "# Travix Linux Script"
echo "########################################################################"
cd build
cmake ..
make
CTEST_OUTPUT_ON_FAILURE=1 make test
./test/test_sdlwrap
