#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <jni.h>
#include <sys/mman.h>
#include <android/log.h>

extern unsigned int unpack2_size;
extern unsigned int unpack2_f_size;

void unpack2_f(unsigned char *func, unsigned int size);
void unpack_f(unsigned char *func, unsigned int size);
