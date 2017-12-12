#include "libJGG.h"
#include "lib/protect.h"

JavaVM *  s_vm = NULL;

void unpack2()
{
    __android_log_print(ANDROID_LOG_INFO, "JGG", "Unpack");

    // xor encryption으로 패킹되어있는 함수 언패킹.
	unpack2_f((unsigned char *)security, security_size);

    __android_log_print(ANDROID_LOG_INFO, "JGG", "unpack - unpack finish");

    // securityCheck 함수 호출.
    security();

    __android_log_print(ANDROID_LOG_INFO, "JGG", "unpack - FIN!");
    return;
}

jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    s_vm = vm;

    // permutaion encryption으로 패킹되어있는 함수 언패킹.
    unpack_f((unsigned char *) unpack2, unpack2_size);
    unpack_f((unsigned char *) unpack2_f, unpack2_f_size);

    unpack_f((unsigned char *) security, security_size);

    __android_log_print(ANDROID_LOG_INFO, "JGG", "JNI_OnLoad - unpack finish");

    // unpack 함수 호출.
    unpack2();

    // JNI_OnLoad
    JNIEnv *env = NULL;

    if(s_vm->GetEnv((void**) &env, JNI_VERSION_1_6) != JNI_OK)
    {
        __android_log_print(ANDROID_LOG_INFO, "JGG", "JNI_VERSION_ERR");
        return JNI_ERR;
    }
    __android_log_print(ANDROID_LOG_INFO, "JGG", "JNI_ONLOAD_FIN!");
    return JNI_VERSION_1_6;
}
