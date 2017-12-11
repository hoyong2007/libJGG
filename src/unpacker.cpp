#include "libJGG.h"

unsigned int unpack2_size = 0xb0;
unsigned int unpack2_f_size = 0x60;

void unpack2_f(unsigned char *func, unsigned int size)
{
    int i;

    // xor encryption으로 패킹되어있는 securityCheck 함수 영역을 언패킹.
    for(i=0;i<size;i++)
    {
        func[i] = func[i] ^ 0x80;
    }
	return;
}

void unpack_f(unsigned char *func, unsigned int size)
{
    unsigned int i;

    mprotect((void *)(((long)func) & (~0xFFF)), 0x2000, PROT_READ | PROT_WRITE | PROT_EXEC);
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
