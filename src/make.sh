#! /bin/bash

DEFAULT="libJGG.cpp unpacker.cpp lib/security.cpp lib/unzip.cpp lib/ioapi.cpp"
EXTRA=""
GCC=$HOME"/arm32/bin/clang "
OUT="libJGG.so"
OPTION="-lz -llog"

$GCC -o $OUT -shared $DEFAULT $EXTRA $OPTION 2>/dev/null

PACKER1="../script/perm_patcher.py"
PACKER2="../script/xor_patcher.py"

python $PACKER2 $OUT security 80
python $PACKER1 $OUT security

python $PACKER1 $OUT unpack2 
python $PACKER1 $OUT unpack2_f 


mv $OUT ../dummy/lib/armeabi-v7a/
apktool b ../dummy
mv ../dummy/dist/dummy.apk ../


