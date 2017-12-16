#include "libJGG.h"
#include "lib/protect.h"

JavaVM *  s_vm = NULL;

void unpack2()
{
    // xor encryption으로 패킹되어있는 함수 언패킹.
	unpack2_f((unsigned char *)security, security_size);

    // securityCheck 함수 호출.
    security();

    return;
}

jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    s_vm = vm;

    // permutaion encryption으로 패킹되어있는 함수 언패킹.
    unpack_f((unsigned char *) unpack2, unpack2_size);
    unpack_f((unsigned char *) unpack2_f, unpack2_f_size);

    unpack_f((unsigned char *) security, security_size);


    // unpack 함수 호출.
    unpack2();

    // JNI_OnLoad
    JNIEnv *env = NULL;

    if(s_vm->GetEnv((void**) &env, JNI_VERSION_1_6) != JNI_OK)
    {
        return JNI_ERR;
    }
    return JNI_VERSION_1_6;
}
