#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <jni.h>
#include <sys/mman.h>
#include <android/log.h>
#include "unzip.h"
#include "protect.h"

void security()
{   
    // rooting
    // /su/bin/su 파일이 존재하고 실행가능한지 여부를 확인함으로써 애플리케이션이 구동되고 있는 기기가 루팅되었는지 확인함.
    __android_log_print(ANDROID_LOG_INFO, "JGG", "Rooting Check");
    {
        if( access("/su/bin/su", F_OK | X_OK) == 0 )
        {
            exit(-1);
        }
    }

    // anti-debugging
    // /proc/self/status의 TracerPid 필드를 확인해 현재 자신을 tracing 하고 있는 프로세스가 있는지 확인함으로써 디버깅 여부를 확인함.
    __android_log_print(ANDROID_LOG_INFO, "JGG", "Anti Debugging");
    {
        FILE *fp;
        char buf[0x100];    
        int tracerPid;

        fp = fopen("/proc/self/status", "r");

        while( fgets(buf, 0x100, fp) != 0 )
        {
            if( strncmp(buf, "TracerPid:\t", 11) == 0 )
            {
                tracerPid = atoi(buf + 11);

                if(tracerPid != 0)
                {
                    exit(-1);
                }

                break;
            }
        }

        fclose(fp);
    }

    // inegrity
    // DEX 파일 헤더의 SHA1 해쉬 값을 읽어와 원본 DEX 파일의 SHA1 해쉬 값과 비교함으로써 DEX 파일의 무결성을 검증.
    __android_log_print(ANDROID_LOG_INFO, "JGG", "Integrity Check");
    {
        FILE *maps_fp = fopen("/proc/self/maps", "r");
        char buf[256];
        char *apkpath;
        char *base;
        unzFile zipfile;
        unz_global_info globalInfo;
        char hash[41];
        int i, j;

        while(fgets(buf, 256, maps_fp))
        {
            apkpath = strstr(buf, "/data/app/jgg.dummy");
            if(apkpath)
            {
                if (base = strchr(apkpath+10, '/')){
                    strcpy(base+1, "base.apk");
                }
                break;
            }
        }

        fclose(maps_fp);

        zipfile = unzOpen(apkpath);

        unzGetGlobalInfo(zipfile, &globalInfo);


        for(i=0;i<globalInfo.number_entry;i++)
        {
            unz_file_info fileInfo;
            char filename[256];

            unzGetCurrentFileInfo(zipfile, &fileInfo, filename, 256, NULL, 0, NULL, 0);

            if(!strcmp(filename, "classes.dex"))
            {
                unzOpenCurrentFile(zipfile);
                unzReadCurrentFile(zipfile, buf, 0xC);
                unzReadCurrentFile(zipfile, buf, 20);
                unzCloseCurrentFile(zipfile);

                for(j=0;j<20;j++)
                {
                    sprintf(hash+2*j, "%02x", buf[j]);
                }

                break;
            }

            if(i+1 < globalInfo.number_entry)
            {
                unzGoToNextFile(zipfile);
            }

        }

        unzClose(zipfile);

        if(strcmp(hash, "5054381a972dc05d996ec1639255beac9a6f6410"))
        {
            exit(-1);
        }
    }

    // emulator
    // Build.PRODUCT 값을 읽어와 키워드 기반 검사를 진행함으로써 애플리케이션이 구동되고 있는 기기가 에뮬레이터인지 확인함.
    __android_log_print(ANDROID_LOG_INFO, "JGG", "Emulator Check");
    {
        JNIEnv *env = NULL;
        jint result = -1;

        if(s_vm->GetEnv((void**) &env, JNI_VERSION_1_6) != JNI_OK)
        {
            __android_log_print(ANDROID_LOG_INFO, "JGG", "JNI_VERSION_ERR");
            exit(-1);
        }

        jclass cls;
        jfieldID fid;
        jstring rtn;
        char *string;
    
        cls = env->FindClass("android/os/Build");
        fid = env->GetStaticFieldID(cls, "PRODUCT", "Ljava/lang/String;");
        rtn = (jstring)env->GetStaticObjectField(cls, fid);
        string = (char*)env->GetStringUTFChars(rtn, 0);
    
        if (!strcmp(string, "sdk") ||
            !strcmp(string, "google_sdk") ||
            !strcmp(string, "sdk_x86") ||
            !strcmp(string, "vbox86p") ||
            !strcmp(string, "nox")) {exit(-1);}    
    }

    __android_log_print(ANDROID_LOG_INFO, "JGG", "security finish");
    return;
}
