#! /bin/bash

~/arm32/bin/clang -shared -lm libJGG.cpp unpacker.cpp lib/security.cpp lib/unzip.cpp lib/ioapi.cpp -lz -llog -o libJGG.so 2>./err
objdump -t libJGG.so | grep unpack
objdump -t libJGG.so | grep security
rm libJGG.so
