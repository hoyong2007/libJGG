1. 이중 패킹으로 보호하고자 하는 네이티브 함수(.cpp)파일을 src/lib/ 디렉토리에 복사해 넣는다.  
	-> 기본적인 security 기능은 jni_onload에 적용되어 있다.  
  
2. src/lib/protect.h에 추가한 함수의 프로토타입을 선언하고, 추가된 .cpp 파일에 include "protect.h" 를 추가한다.   
  
3. src/libJGG.cpp의 jni_onload()와 unpack2()에 추가된 함수의 언패킹 부분을 추가한다. 이때 두 번째 인자는 [함수이름]_size로 한다. ex) security_size
	->	JNI_OnLoad(){  
			...   
			unpack_f((unsigned char*)func, func_size);  
			...  
		}  
	->	unpack2(){  
			...    
			unpack2_f((unsigned char*)func, func_size);  
			...   
		}  
  
4. src/check_info.sh와 src/make.sh 파일의 컴파일 부분에 추가된 cpp 파일을 추가한다.   
	-> ~/arm32/bin/clang .... func.cpp -o libJGG.so ...   
     
5. src/check_info와 src/make.sh 의 패치부분에 추가된 함수를 패치하는 부분을 추가한다.  
	- src/check_info.sh  
		-> python ../script/check_info.py libJGG.so func  
	- src/make.sh
		-> python ../script/xor_patcher.py ../script/libJGG.so func 80  
		-> python ../script/perm_patcher.py ../script/libJGG.so func  

6. src/check_info.sh를 사용해 추가된 함수의 크기를 얻어온 뒤에 protect.h에 [함수명]_size 라는 이름으로 상수를 추가한다.  
	->	#ifndef JGG   
		...  
		const unsigned int func_size = 0xXX;  
		#endif  
  
7. src/make.sh를 사용해 라이브러리를 빌드한다  
