#! /bin/bash

~/arm32/bin/clang -shared -lm libJGG.cpp unpacker.cpp lib/security.cpp lib/unzip.cpp lib/ioapi.cpp -lz -llog -o libJGG.so 2>./err
python ../script/check_info.py libJGG.so unpack2
python ../script/check_info.py libJGG.so unpack2_f
python ../script/check_info.py libJGG.so security
rm libJGG.so
