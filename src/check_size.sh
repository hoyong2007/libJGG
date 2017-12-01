#! /bin/bash

~/arm32/bin/clang -shared security_chk.cpp -o libJGG.so
objdump -t libJGG.so | grep _Z6unpackP7_JavaVM
objdump -t libJGG.so | grep _Z13securityCheckP7_JavaVM
rm libJGG.so
