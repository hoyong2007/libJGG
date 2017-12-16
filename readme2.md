libJGG 매뉴얼  
===============  
1. 준비 사항  
--------------  
	- download & install android-ndk  
		-> $ curl -O http://dl.google.com/android/repository/android-ndk-r12b-linux-x86_64.zip  
		-> $ unzip android-ndk-r12b-linux-x86_64.zip  
		-> $ python ./android-ndk-r12b/build/tools/make_standalone_toolchain.py --arch arm --install-dir ~/arm32  
  
	- custom 함수  
		-> 라이브러리를 로드하지 않게 함으로써 모듈을 떼어내는 것을 방지하기 위해 App의 정상적인 실행을 위한 함수를 1개 이상 라이브러리 내부에 탑재해야 한다.  
  
  
2. custom 함수 및 JNI_OnLoad시의 액션 추가  
--------------------------------------------
	- 보호하고자 하는 .cpp파일을 src/lib/폴더 안에 넣고 protect.h 헤더파일을 include 한다.  
	- src/lib/protect.h 헤더파일에 추가된 함수의 프로타입을 선언하고 함수 사이즈 상수를 추가한다. (상수값은 0x0으로 초기화)  
	- src/libJGG.cpp의 JNI_OnLoad()함수와 unpack2()함수에 추가된 함수의 언패킹 과정을 추가한다.   
	- 각 쉘 스크립트(check_info.sh, make.sh)에 추가된 함수에 대한 내용을 추가한다.  
	- src/check_info.sh를 사용해 얻은 추가된 함수의 크기를 이용해 src/lib/protect.h에 선언된 함수 사이즈 상수의 값과 src/libJGG.h에 선언된 unpack2_size 상수값을 수정한다.  
	- src/make.sh를 사용해 라이브러리를 빌드한다.  
	- JNI_OnLoad시 함수를 호출하고 싶다면 추가된 함수를 src/libJGG.cpp의 unpack2()함수 마지막 부분에 함수 호출을 하면 된다.  
