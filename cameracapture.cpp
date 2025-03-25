#include "cameracapture.h"

CameraCapture::CameraCapture(QObject *parent, QString id, QQueue<QString> *queueTemp,    QMutex *locker)
    : QObject(parent),m_id(id),m_queueTemp(queueTemp),m_locker(locker)
{

    Cap = new VideoCapture(id.toStdString().c_str());
    Cap->setExceptionMode(true);
    // Cap.open(id.toStdString().c_str());
    // //Cap.setExceptionMode(true);
    // //Cap.set(CAP_PROP_BUFFERSIZE,1);
    // qDebug()<<"Buffer:  "<<    Cap.get(CAP_PROP_BUFFERSIZE); // internal buffer will now store only 3 frames

    //Cap.set(CAP_PROP_BUFFERSIZE, 2); // internal buffer will now store only 3 frames
    if (!Cap->isOpened()) {
        qDebug() << "ERROR! Unable to open camera"<< "  id:"<<id.toStdString().c_str();
    }
    // Cap.set(CAP_PROP_FRAME_WIDTH, 1280);
    // Cap.set(CAP_PROP_FRAME_HEIGHT, 720);
    //Cap.set(CAP_PROP_FPS, 30);

    qDebug()<<"ID:"<<id<<"  Inıtilaized Camera Settings, Start grabbing "<<"Fps:"<<Cap->get(CAP_PROP_FPS)<<"     FrameCount:"<<Cap->get(CAP_PROP_FRAME_COUNT) ;
    qDebug()<< "Inıtilaized Camera Settings, Start grabbing";
    qDebug()<<Cap->get(CAP_PROP_FRAME_WIDTH)<<" x "<<Cap->get(CAP_PROP_FRAME_HEIGHT);
    qDebug()<<"OpenCV Version:  "<<CV_VERSION;

}

void rotateFrame(Mat &Frame)
{
    if (!Frame.empty()) {
        cv::flip(Frame, Frame, 1);
    }
}

void CameraCapture::captureFrame()
{
    while (Cap->isOpened()) {
        //locker.lock();

        Cap->read(Frame);
        cv::imwrite("build/Desktop_Qt_6_5_3_GCC_64bit-Release/HDR/2.png",Frame);
        // rotateFrame(Frame);
        // locker.unlock();
        if (!Frame.empty()) {
            emit getFrame();
        }
        //QThread::currentThread()->msleep(1000/33);
        // locker.lock();
        // Frame.release();
        // locker.unlock();
    }
}
