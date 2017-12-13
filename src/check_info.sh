#! /bin/bash

DEFAULT="libJGG.cpp unpacker.cpp lib/security.cpp lib/unzip.cpp lib/ioapi.cpp"
EXTRA=""
GCC=$HOME"/arm32/bin/clang "
OUT="libJGG.so"
OPTION="-lz -llog"

$GCC -o $OUT -shared $DEFAULT $EXTRA $OPTION 2>err

SCRIPT="../script/check_info.py"
python $SCRIPT $OUT unpack2
python $SCRIPT $OUT unpack2_f
python $SCRIPT $OUT security

rm libJGG.so


