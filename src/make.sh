#! /bin/bash

~/arm32/bin/clang -shared -lm main.cpp unzip.cpp ioapi.cpp -lz -o libJGG.so 2>/dev/null
echo "build success!"

python ../script/xor_patcher.py libJGG.so security 80
python ../script/perm_patcher.py libJGG.so unpack
echo "Patch Fin!"

mv ./libJGG ../dummy/lib/armeabi-v7a/
cd ..
apktool b dummy/
cp ./dummy/dist/dummy.apk ./
echo "Done."
