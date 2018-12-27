#ifndef RIDESINTERFACE_H
#define RIDESINTERFACE_H

#endif // RIDESINTERFACE_H
#include "jni.h"

#include <QDebug>
typedef struct _RideFilePoint {
    jclass cls;
    jmethodID constructortorID;
    jfieldID hr;
    jfieldID km;
    jfieldID lon;
    jfieldID lat;
    jfieldID secs;
}_RideFilePoint;

_RideFilePoint * jniRidePointStruct = NULL;

void createRideFilePointJavaObject(JNIEnv *env){
    qDebug() << "Creating the RideFilePoint";
    jniRidePointStruct = new _RideFilePoint;
    jniRidePointStruct->cls = env->FindClass("com/svlabs/svt/ride/RideFilePoint");
    if(jniRidePointStruct->cls != NULL)
        qDebug() <<"sucessfully created com/svlabs/svt/ride/RideFilePoint";
    jniRidePointStruct->constructortorID = env->GetMethodID(jniRidePointStruct->cls, "<init>", "()V");
    if(jniRidePointStruct->constructortorID != NULL){
        qDebug() << "sucessfully created RideFilePoint constructor   ";
    }
    jniRidePointStruct->hr = env->GetFieldID(jniRidePointStruct->cls, "hr", "D");
    jniRidePointStruct->km = env->GetFieldID(jniRidePointStruct->cls, "km", "D");
    jniRidePointStruct->lon = env->GetFieldID(jniRidePointStruct->cls, "lon", "D");
    jniRidePointStruct->lat = env->GetFieldID(jniRidePointStruct->cls, "lat", "D");
    jniRidePointStruct->secs = env->GetFieldID(jniRidePointStruct->cls, "secs", "D");
    qDebug() << "Successfully created RideFilePoint";
}

