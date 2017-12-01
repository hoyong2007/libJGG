#! /bin/bash

~/arm32/bin/clang -shared -lm main.cpp unzip.cpp ioapi.cpp -lz -o libJGG.so
