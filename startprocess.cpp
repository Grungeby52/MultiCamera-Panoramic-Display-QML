#include "startprocess.h"

StartProcess::StartProcess(QObject *parent)
    : QObject{parent}
{
    cap_0 = new CameraCapture(nullptr,source1,&queueTemp,&locker);
    future_0 = QtConcurrent::run(&CameraCapture::captureFrame, cap_0);
    connect(cap_0,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_0,Qt::AutoConnection);

    // cap_1 = new CameraCapture(nullptr,source2,&queueTemp,&locker);
    // future_1 = QtConcurrent::run(&CameraCapture::captureFrame, cap_1);
    // connect(cap_1,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_1,Qt::AutoConnection);

    // cap_2 = new CameraCapture(nullptr,source3,&queueTemp,&locker);
    // future_2 = QtConcurrent::run(&CameraCapture::captureFrame, cap_2);
    // connect(cap_2,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_2,Qt::AutoConnection);

    // cap_3 = new CameraCapture(nullptr,source4,&queueTemp,&locker);
    // future_3 = QtConcurrent::run(&CameraCapture::captureFrame, cap_3);
    // connect(cap_3,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_3,Qt::AutoConnection);

    // cap_4 = new CameraCapture(nullptr,source5,&queueTemp,&locker);
    // future_4 = QtConcurrent::run(&CameraCapture::captureFrame, cap_4);
    // connect(cap_4,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_4,Qt::AutoConnection);

    // cap_5 = new CameraCapture(nullptr,source6,&queueTemp,&locker);
    // future_5 = QtConcurrent::run(&CameraCapture::captureFrame, cap_5);
    // connect(cap_5,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_5,Qt::AutoConnection);

    // cap_6 = new CameraCapture(nullptr,source7,&queueTemp,&locker);
    // future_6 = QtConcurrent::run(&CameraCapture::captureFrame, cap_6);
    // connect(cap_6,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_6,Qt::AutoConnection);

    // cap_7 = new CameraCapture(nullptr,source8,&queueTemp,&locker);
    // future_7 = QtConcurrent::run(&CameraCapture::captureFrame, cap_7);
    // connect(cap_7,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_7,Qt::AutoConnection);

    // cap_8 = new CameraCapture(nullptr,source9,&queueTemp,&locker);
    // future_8 = QtConcurrent::run(&CameraCapture::captureFrame, cap_8);
    // connect(cap_8,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_8,Qt::AutoConnection);

    //operationFrame = new FrameOperations();

    connect(this,&StartProcess::getFrame,this,&StartProcess::streamVideo,Qt::AutoConnection);

}


QImage StartProcess::mirrorHorizontally(const QImage &image) {
    int width = image.width();
    int height = image.height();
    QImage mirroredImage(width, height, image.format());

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            QColor color = image.pixelColor(width - x - 1, y);
            mirroredImage.setPixelColor(x, y, color);
        }
    }

    return mirroredImage;
}

void rotateFrameCamera(Mat &Frame)
{
    if (!Frame.empty()) {
        try {
            cv::flip(Frame, Frame, 1);

        } catch (int e) {

        }
    }
}

// void manualFlip(cv::Mat &Frame) {

//     if (!Frame.empty()) {
//         cv::flip(Frame, Frame, 1);
//     }

// }

void StartProcess::newFrameCamera_0()
{
    // rotateFrameCamera(cap_0->Frame);
    frame = cap_0->Frame;
    temp.frame = frame;
    temp.id = cap_0->m_id;
    emit getFrame();
}

void StartProcess::newFrameCamera_1()
{
    // rotateFrameCamera(cap_1->Frame);
    frame = cap_1->Frame;
    temp.frame = frame;
    temp.id = cap_1->m_id;
    emit getFrame();
}

void StartProcess::newFrameCamera_2()
{
    // rotateFrameCamera(cap_2->Frame);
    frame = cap_2->Frame;
    temp.frame = frame;
    temp.id = cap_2->m_id;
    emit getFrame();
}

void StartProcess::newFrameCamera_3()
{
     // rotateFrameCamera(cap_3->Frame);
    frame = cap_3->Frame;
    temp.frame = frame;
    temp.id = cap_3->m_id;
    emit getFrame();
}

void StartProcess::newFrameCamera_4()
{
    // rotateFrameCamera(cap_4->Frame);
    frame = cap_4->Frame;
    temp.frame = frame;
    temp.id = cap_4->m_id;
    emit getFrame();
}

void StartProcess::newFrameCamera_5()
{
    // rotateFrameCamera(cap_5->Frame);
    frame = cap_5->Frame;
    temp.frame = frame;
    temp.id = cap_5->m_id;
    emit getFrame();
}

void StartProcess::newFrameCamera_6()
{
    // rotateFrameCamera(cap_6->Frame);
    frame = cap_6->Frame;
    // rotateFrameCamera(frame);
    temp.frame = frame;
    temp.id = cap_6->m_id;
    emit getFrame();
}

void StartProcess::newFrameCamera_7()
{
     // rotateFrameCamera(cap_7->Frame);
    frame = cap_7->Frame;
    temp.frame = frame;
    temp.id = cap_7->m_id;
    emit getFrame();
}

void StartProcess::newFrameCamera_8()
{
    // rotateFrameCamera(cap_8->Frame);
    frame = cap_8->Frame;
     // rotateFrameCamera(frame);
    temp.frame = frame;
    temp.id = cap_8->m_id;
    emit getFrame();
}


void StartProcess::streamVideo()
{

    if (temp.id == source1) {
        QImage img_0 = QImage((uchar*)frame.data,frame.cols,frame.rows,frame.step1(),QImage::Format_RGB888).rgbSwapped();
        emit newImage_0(img_0.mirrored(true,false));
    }
    if (temp.id == source2) {
        QImage img_1 = QImage((uchar*)frame.data,frame.cols,frame.rows,frame.step1(),QImage::Format_RGB888).rgbSwapped();
        emit newImage_1(img_1.mirrored(true,false));
    }
    if (temp.id == source3) {
        QImage img_2 = QImage((uchar*)frame.data,frame.cols,frame.rows,frame.step1(),QImage::Format_RGB888).rgbSwapped();
        emit newImage_2(img_2.mirrored(true,false));
    }
    if (temp.id == source4) {
        QImage img_3 = QImage((uchar*)frame.data,frame.cols,frame.rows,frame.step1(),QImage::Format_RGB888).rgbSwapped();
        emit newImage_3(img_3.mirrored(true,false));
    }
    if (temp.id == source5) {
        QImage img_4 = QImage((uchar*)frame.data,frame.cols,frame.rows,frame.step1(),QImage::Format_RGB888).rgbSwapped();
        emit newImage_4(img_4.mirrored(true,false));
    }
    if (temp.id == source6) {
        QImage img_5 = QImage((uchar*)frame.data,frame.cols,frame.rows,frame.step1(),QImage::Format_RGB888).rgbSwapped();
        emit newImage_5(img_5.mirrored(true,false));
    }
    if (temp.id == source7) {
        QImage img_6 = QImage((uchar*)frame.data,frame.cols,frame.rows,frame.step1(),QImage::Format_RGB888).rgbSwapped();
        emit newImage_6(img_6.mirrored(true,false));
    }
    if (temp.id == source8) {
        QImage img_7 = QImage((uchar*)frame.data,frame.cols,frame.rows,frame.step1(),QImage::Format_RGB888).rgbSwapped();
        emit newImage_7(img_7.mirrored(true,false));
    }
    if (temp.id == source9) {
        QImage img_8 = QImage((uchar*)frame.data,frame.cols,frame.rows,frame.step1(),QImage::Format_RGB888).rgbSwapped();
        emit newImage_8(img_8.mirrored(true,false));
    }
}
