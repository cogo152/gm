#!/bin/bash

rm -rf build

cmake   --no-warn-unused-cli            \
        -Wno-dev                        \
        -DDEV_LOCAL:BOOL=TRUE           \
        -S.                             \
        -B build                        \
        -G "Unix Makefiles"             \

cmake   --build build                   \
        --target all                    \
        -j 14 --