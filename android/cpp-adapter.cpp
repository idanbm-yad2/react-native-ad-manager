#include <jni.h>
#include "react-native-ad-manager.h"

extern "C" JNIEXPORT jint JNICALL
Java_com_reactnativeadmanager_AdManagerModule_nativeMultiply(JNIEnv *env, jclass type, jint a, jint b)
{
    return multiply(a, b);
}

extern "C" JNIEXPORT void JNICALL
Java_com_reactnativeadmanager_AdManagerModule_initialize(JNIEnv *env, jclass clazz, jlong jsiPtr)
{
    installExample(*reinterpret_cast<facebook::jsi::Runtime *>(jsiPtr));
}
