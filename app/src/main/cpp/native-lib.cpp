//
// Created by Manikanta on 13-10-2021.
//

#include <jni.h>
#include <string>
#include <iostream>
using namespace std;

extern "C" JNIEXPORT jstring

JNICALL
Java_com_example_myapplication_Keys_apiKey(JNIEnv *env, jobject object) {

    static string api_key,api_key10;

    api_key ="9a0sdgm0u09adsgcfasdfhc";
    return env->NewStringUTF(api_key.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_myapplication_Keys_apiKeys(JNIEnv *env, jobject thiz) {
    // TODO: implement apiKeys
    static string api_key,api_key1;
     api_key1 = "TmF0aXZlNWVjcmV0UEBzc3cwcmQy";
    return env->NewStringUTF(api_key1.c_str());
}
