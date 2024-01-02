#!/bin/bash

qemu-system-arm -M netduinoplus2 -L /usr/lib/arm-none-eabi/lib -kernel ./build/gm-kernel