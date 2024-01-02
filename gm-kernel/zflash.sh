#!/bin/bash

openocd -d                                                                      \
        -f interface/stlink.cfg                                                 \
        -f board/stm32f4discovery.cfg                                           \
        -c init                                                                 \
        -c "reset halt"                                                         \
        -c "flash write_image erase ${PWD}/build/gm-kernel.bin 0x08000000"      \
        -c "reset"
                                                                      
#        -c "arm semihosting enable"
