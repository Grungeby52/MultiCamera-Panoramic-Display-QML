/**
 * @author Onur GÜZELDEMİRCİ
 * @company AnzatsanMühendislik
 * @date 12.10.2024
 */
#ifndef STARTPROCESS_H
#define STARTPROCESS_H

#include <QObject>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>
#include <QQueue>
#include <QMutex>
#include <QtNetwork>
#include <QThread>
#include <QImage>
#include "cameracapture.h"
#include "CamFrameId.h"
#include "frameoperations.h"
#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/imgproc.hpp>

using namespace cv;

class StartProcess : public QObject
{
    Q_OBJECT
public:
    explicit StartProcess(QObject *parent = nullptr);
    CameraCapture *cap_0;
    CameraCapture *cap_1;
    CameraCapture *cap_2;
    CameraCapture *cap_3;
    CameraCapture *cap_4;
    CameraCapture *cap_5;
    CameraCapture *cap_6;
    CameraCapture *cap_7;
    CameraCapture *cap_8;

public slots:
    void newFrameCamera_0();
    void newFrameCamera_1();
    void newFrameCamera_2();
    void newFrameCamera_3();
    void newFrameCamera_4();
    void newFrameCamera_5();
    void newFrameCamera_6();
    void newFrameCamera_7();
    void newFrameCamera_8();


    void streamVideo();

signals:

    void newImage_0(QImage );
    void newImage_1(QImage );
    void newImage_2(QImage );
    void newImage_3(QImage );
    void newImage_4(QImage );
    void newImage_5(QImage );
    void newImage_6(QImage );
    void newImage_7(QImage );
    void newImage_8(QImage );

    void getFrame();

private:

    cv::Mat m_temp_0 ;
    cv::Mat m_temp_1 ;
    cv::Mat m_temp_2 ;
    cv::Mat m_temp_3 ;
    cv::Mat m_temp_4 ;
    cv::Mat m_temp_5 ;
    cv::Mat m_temp_6 ;
    cv::Mat m_temp_7 ;
    cv::Mat m_temp_8 ;

    cv::Mat m_concatenated_frame;
    cv::Mat sendFrames(QQueue<CamFrameId> &matQueueMain);
    QImage mirrorHorizontally(const QImage &image);
    QQueue<CamFrameId> m_matQueueMain;

    QFuture<void> future_0;
    QFuture<void> future_1;
    QFuture<void> future_2;
    QFuture<void> future_3;
    QFuture<void> future_4;
    QFuture<void> future_5;
    QFuture<void> future_6;
    QFuture<void> future_7;
    QFuture<void> future_8;

    // FrameOperations *operationFrame;
    int selectedID = 2;

    int frameCounter = 0;

    QQueue<QString> queueTemp;
    QMutex locker;

    CamFrameId temp;
    Mat frame;


// 3. video dolu pc uzerinde 4.bnc
    //5. video dolu pc uzerinde 6. video


    QString source1="/dev/video0"; //Sol Ön Kamera
    QString source2="v4l2src device=/dev/video5 ! video/x-raw, width=1280, height=720  ! videoconvert ! appsink";
    QString source3="v4l2src device=/dev/video6 ! video/x-raw, width=1280, height=720 ! videoconvert ! appsink";

    QString source4="v4l2src device=/dev/video9 ! video/x-raw, width=1280, height=720 ! videoconvert ! videoflip method=horizontal-flip ! appsink"; //Sağ Ön Kamera

    QString source5="v4l2src device=/dev/video4 ! video/x-raw, width=1280, height=720 ! videoconvert ! appsink";
    QString source6="v4l2src device=/dev/video3 ! video/x-raw, width=1280, height=720 ! videoconvert ! appsink";

    QString source7="v4l2src device=/dev/video7 ! video/x-raw, width=1280, height=720 ! videoconvert ! appsink"; //Ön Kamera
    QString source8="v4l2src device=/dev/video8 ! video/x-raw, width=1280, height=720 ! videoconvert ! videoflip method=horizontal-flip ! appsink"; //Arka Kamera

    QString source9="v4l2src device=/dev/video1 ! video/x-raw, width=1280, height=720 ! videoconvert ! videoflip method=horizontal-flip ! appsink";

    //QString source1="/home/batuhanokmen/QtProject/renkDegistirme/test9.mp4";
    // QString source2="/home/batuhanokmen/QtProject/renkDegistirme/test22.mp4";
    // QString source3="/home/batuhanokmen/QtProject/renkDegistirme/test32.mp4";
    // QString source4="/home/batuhanokmen/QtProject/renkDegistirme/test43.mp4";
    // QString source5="/home/batuhanokmen/QtProject/renkDegistirme/test53.mp4";
    // QString source6="/home/batuhanokmen/QtProject/renkDegistirme/test6.mp4";
    // QString source7="/home/batuhanokmen/QtProject/renkDegistirme/test74.mp4";
    //QString source8="/home/batuhanokmen/QtProject/renkDegistirme/test8.mp4";
    //QString source9="/home/batuhanokmen/QtProject/renkDegistirme/test10.mp4";

    // QString source1="/home/ds1402-1/Downloads/videoTest4.mp4";
    // QString source2="/home/ds1402-1/Downloads/videoTest4.mp4";
    // QString source3="/home/ds1402-1/Downloads/videoTest4.mp4";
    // QString source4="/home/ds1402-1/Downloads/videoTest4.mp4";
    // QString source5="/home/ds1402-1/Downloads/videoTest5.mp4";
    // QString source6="/home/ds1402-1/Downloads/videoTest6.mp4";
    // QString source7="/home/ds1402-1/Downloads/videoTest7.mp4";
    // QString source8="/home/ds1402-1/Downloads/videoTest8.mp4";
    // QString source9="/home/ds1402-1/Downloads/videoTest.mp4";


    bool isFlipped_0 = false;
    bool isFlipped_1 = false;
    bool isFlipped_2 = false;
    bool isFlipped_3 = false;
    bool isFlipped_4 = false;
    bool isFlipped_5 = false;
    bool isFlipped_6 = false;
    bool isFlipped_7 = false;
    bool isFlipped_8 = false;

};

#endif // STARTPROCESS_H
