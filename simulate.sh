#!/bin/bash

simavr -mcu atmega328 -freq 16000000 balancer.hex -g &
avr-gdb balancer.elf -ex "target remote :1234"
pkill simavr

