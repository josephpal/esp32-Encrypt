#!/bin/bash

# src:    https://github.com/espressif/esp-idf/blob/master/docs/api-reference/storage/spiffs.rst
#         https://github.com/igrr/mkspiffs/releases -> version 2.1

# Name,   Type, SubType, Offset,  Size, Flags
# nvs,      data, nvs,     0x9000,  0x5000,
# otadata,  data, ota,     0xe000,  0x2000,
# app0,     app,  ota_0,   0x10000, 0x140000,
# app1,     app,  ota_1,   0x150000,0x140000,
# eeprom,   data, 0x99,    0x290000,0x1000,
# spiffs,   data, spiffs,  0x291000,0x16F000, 

clear;

echo "makeSPIFFS.sh v1.0"
echo

./mkspiffs -c ./data/ -b 4096 -p 256 -s 0x16F000 spiffs.bin

echo

python ./esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 115200 write_flash -z 0x291000 ./spiffs.bin
