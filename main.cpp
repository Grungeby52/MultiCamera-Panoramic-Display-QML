#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include <opencvimageprovider.h>
#include <startprocess.h>
int counter = 0;
bool TEST_PC=false;
QSize VrScreen(1920, 1080);


OpencvImageProvider *liveImageProvider_0(new OpencvImageProvider);
StartProcess *start;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QList<QScreen *> screens = app.screens();
    start = new StartProcess();
    QQmlApplicationEngine engine ;

    engine.rootContext()->setContextProperty("liveImageProvider_0",liveImageProvider_0);
    engine.addImageProvider("live_0",liveImageProvider_0);

    QObject::connect(start,&StartProcess::newImage_0,liveImageProvider_0,&OpencvImageProvider::updateImage);


    const QUrl url(QStringLiteral("qrc:/PanoramicTestQML/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
