#include "libJGG.h"


/* unpack2에서 두번째 언패킹을 수행하는 함수 */
void unpack2_f(unsigned char *func, unsigned int size)
{
    int i;

	// xor decoding을 통해 두번째 언패킹 수행
    for(i=0;i<size;i++)
    {
        func[i] = func[i] ^ 0x80;
    }
	return;
}


/* JNI_OnLoad에서 첫번째 언패킹을 수행하는 함수 */
void unpack_f(unsigned char *func, unsigned int size)
{
    unsigned int i;

	// 패킹되어있는 함수의 영역의 권한을 RWX 권한으로 설정한다
    mprotect((void *)(((long)func) & (~0xFFF)), 0x2000, PROT_READ | PROT_WRITE | PROT_EXEC);

    // permutaion decoding을 통해 첫번째 언패킹 수행 
    for(i=0;i<size/7;i++)
    {
        func[i*7+2]^=func[i*7+3];
        func[i*7+3]^=func[i*7+2];
        func[i*7+2]^=func[i*7+3];

        func[i*7+2]^=func[i*7+6];
        func[i*7+6]^=func[i*7+2];
        func[i*7+2]^=func[i*7+6];

        func[i*7+5]^=func[i*7+0];
        func[i*7+0]^=func[i*7+5];
        func[i*7+5]^=func[i*7+0];

        func[i*7+1]^=func[i*7+5];
        func[i*7+5]^=func[i*7+1];
        func[i*7+1]^=func[i*7+5];

        func[i*7+1]^=func[i*7+4];
        func[i*7+4]^=func[i*7+1];
        func[i*7+1]^=func[i*7+4];

        func[i*7+2]^=func[i*7+4];
        func[i*7+4]^=func[i*7+2];
        func[i*7+2]^=func[i*7+4];
    }
}
