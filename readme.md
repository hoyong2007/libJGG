1. check_info.sh  
	=> 라이브러리 컴파일 후 unpack과 security의 사이즈를 출력해주는 스크립트

2. xor 연산 & permutation을 수행하는 부분의 각 함수(unpack, security)크기 부분을 수정

3. make.sh  
	=> 라이브러리 컴파일 + 패킹 + apk 빌드후 루트 디렉토리에 dummy.apk 파일을 떨궈주는 쉘 스크립트  

4. xor_patcher.py  
	=> xor packing을 수행해주는 스크립트  
	=> Usage : python xor_patcher.py [ target ] [ symbol ] [ hex-encoded key ]  
	-> $ python xor_patcher.py libJGG.so security 80  

5. perm_patcher.py  
	=> permutaion을 수행해주는 스크립트  
	=> Usage : python perm_patcher.py [target] [symbol]  
	-> $ python perm_patcher.py libJGG.so unpack  
  
6. 루트 디렉토리에 떨어진 dummy.apk를 signing만 해주면 끝~~~!!  
