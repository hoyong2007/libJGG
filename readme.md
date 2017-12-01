1. check_size.sh
	=> 라이브러리 컴파일 후 unpack과 security의 사이즈를 출력해주는 스크립트

2. xor 연산을 수행하는 부분의 각 함수(unpack, security)크기 부분을 수정

3. make.sh
	=> 라이브러리 컴파일

4. xor_patcher.py
	=> xor packing을 수행해주는 스크립트
	=> Useage : python xor_patcher.py [ target ] [ symbol ] [ hex-encoded key ]
	-> $ python xor_patcher.py libJGG.so unpack 40
	-> $ python xor_patcher.py libJGG.so security 80

5. cp ./libJGG.so ./dummy/lib/armeabi-v7a/

6. apktool b dummy
