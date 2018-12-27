#include "matriccaltest.h"
#include "RideMetric.h"
#include "Specification.h"
#include "Settings.h"

MatricCalTest::MatricCalTest()
{

}
int main(int argc, char *argv[])
{
     //appsettings->migrateQSettingsSystem();
    QList<RideFile*> rides;
    QStringList errors;
    QFile fitFile("/Users/chiranjeevi/MyData/fit/Fit files from Subbu/RunningFIT.fit");
    RideFile *ride = RideFileFactory::instance().openRideFile(NULL, fitFile, errors, &rides);
    if(ride){
        //RideFile f(const_cast<RideFile*>(ride));
        RideItem *rideItem = new RideItem(ride, NULL);
        QVector<RideFilePoint*> allPoints = ride->dataPoints();
        for (int i=0;i<allPoints.size();i++) {
             RideFilePoint *eachPoint = allPoints.at(i);
             //qDebug() << "HR " << eachPoint->hr;
        }
          /*if (rideItem->ride() == NULL)
              qDebug() << "No ride";
          else {
               qDebug() << "Has ride";
          }
          if(rideItem->ride()->areDataPresent()->hr)
              qDebug() << "No HR Data";
          else {
               qDebug() << "HR Data";
          }
         QVector<RideFilePoint*> dPoints = rideItem->ride()->dataPoints();
          qDebug() << rideItem->ride()->dataPoints().count() ;*/
        QString s = GC_SETTINGS_INTERVAL_METRICS_DEFAULT;
        QStringList intervalMetrics = s.split(',');
        QStringList testMatrics = {"max_speed"};
         const RideMetricFactory &factory = RideMetricFactory::instance();
         QHash<QString,RideMetricPtr> notmetrics = RideMetric::computeMetrics(rideItem, Specification(),testMatrics);
         QHashIterator<QString, RideMetricPtr> i(notmetrics);
         while (i.hasNext()) {
             i.next();
             RideMetricPtr rideMatPtr = i.value();
             QString key = i.key();
             qDebug() << "Key : "+key+" RideMatValue: "<<rideMatPtr->value();
         }
    }
    return 0;
}
