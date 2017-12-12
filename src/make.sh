#! /bin/bash
~/arm32/bin/clang -shared -lm libJGG.cpp unpacker.cpp lib/security.cpp lib/unzip.cpp lib/ioapi.cpp -lz -llog -o libJGG.so 2>/dev/null

mv libJGG.so ../script/
python ../script/xor_patcher.py ../script/libJGG.so security 80
python ../script/perm_patcher.py ../script/libJGG.so security
python ../script/perm_patcher.py ../script/libJGG.so unpack2 
python ../script/perm_patcher.py ../script/libJGG.so unpack2_f 


mv ../script/libJGG.so ../dummy/lib/armeabi-v7a/
apktool b ../dummy
mv ../dummy/dist/dummy.apk ../
