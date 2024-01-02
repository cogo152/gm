#!/bin/bash

qemu-system-arm \
  -M netduinoplus2 \
  -nographic \
  -semihosting-config enable=on,target=native \
  -kernel ./build/gm-kernel

