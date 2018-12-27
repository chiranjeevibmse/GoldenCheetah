#include "com_svlabs_svt_ride_SaarRideFileReader.h"
#include <QDebug>
#include <QString>
#include "RideFile.h"
#include "FitRideFile.h"
#include <QFile>
#include <QList>
#include "Settings.h"
#include <vector>
#include "ridesinterface.h"



jobjectArray Java_com_svlabs_svt_ride_SaarRideFileReader_readFile(JNIEnv * env, jobject, jstring fileName)
{
    qDebug()<<"Call in RideFile Read";
    QList<RideFile*> rides;
    QStringList errors;
    const char * inString = env->GetStringUTFChars(fileName, NULL);
    QFile fitFile(inString);
    env->ReleaseStringUTFChars(fileName,inString);
    RideFile *ride = RideFileFactory::instance().openRideFile(NULL, fitFile, errors, &rides);
    if(ride){
        qDebug()<<"Has Ride";
        QVector<RideFilePoint*> allPoints = ride->dataPoints();
        createRideFilePointJavaObject(env);
        jobjectArray jiniRidePointArray = env->NewObjectArray(allPoints.size(), jniRidePointStruct->cls, NULL);
        for (int i=0;i<allPoints.size();i++) {
             RideFilePoint *eachPoint = allPoints.at(i);
             jobject jniRidePoint = env->NewObject(jniRidePointStruct->cls, jniRidePointStruct->constructortorID);
             env->SetDoubleField(jniRidePoint,jniRidePointStruct->hr,eachPoint->hr);
             env->SetDoubleField(jniRidePoint,jniRidePointStruct->secs,eachPoint->secs);
             env->SetDoubleField(jniRidePoint,jniRidePointStruct->km,eachPoint->km);
             env->SetDoubleField(jniRidePoint,jniRidePointStruct->lon,eachPoint->lon);
             env->SetDoubleField(jniRidePoint,jniRidePointStruct->lat,eachPoint->lat);
             env->SetObjectArrayElement(jiniRidePointArray, i, jniRidePoint);
             //qDebug()<<"Adding :"<<i;
        }
        qDebug()<<"Returning :";
        return jiniRidePointArray;
    }
    qDebug()<<"No Ride";
}
