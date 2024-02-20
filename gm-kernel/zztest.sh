#!/bin/bash

rm -rf build

cmake   --no-warn-unused-cli            \
        -Wno-dev                        \
        -DDEV_LOCAL:BOOL=TRUE           \
        -DSEMIHOST:BOOL=TRUE            \
        -S.                             \
        -B build                        \
        -G "Unix Makefiles"             \

cmake   --build build                   \
        --target all test               \
        -j 14 --