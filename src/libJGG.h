#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <jni.h>
#include <sys/mman.h>
#include <android/log.h>

#ifndef JGG
#define JGG
const unsigned int unpack2_size = 0xa0;
const unsigned int unpack2_f_size = 0x60;
#endif

void unpack2_f(unsigned char *func, unsigned int size);
void unpack_f(unsigned char *func, unsigned int size);
