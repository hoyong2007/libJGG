#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <jni.h>
#include <sys/mman.h>
#include <android/log.h>

#ifndef UNPACK
const unsigned int unpack2_size = 0xb0;
const unsigned int unpack2_f_size = 0x60;
#define UNPACK
#endif

void unpack2_f(unsigned char *func, unsigned int size);
void unpack_f(unsigned char *func, unsigned int size);
