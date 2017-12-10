#! /bin/bash

~/arm32/bin/clang -shared -lm main.cpp unzip.cpp ioapi.cpp -lz -llog -o libJGG.so 2>./err
objdump -t libJGG.so | grep unpack
objdump -t libJGG.so | grep security
rm libJGG.so
