/**
 * @author Onur GÜZELDEMİRCİ
 * @company AnzatsanMühendislik
 * @date 12.10.2024
 */
#ifndef OPENCVIMAGEPROVIDER_H
#define OPENCVIMAGEPROVIDER_H


#include <QObject>
#include <QImage>
#include <QQuickImageProvider>

class OpencvImageProvider : public QQuickImageProvider
{
    Q_OBJECT
public:
    OpencvImageProvider(QObject *parent = nullptr);
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;

public slots:
    void updateImage(const QImage &image);

signals:
    void imageChanged();

private:
    QImage image;
};

#endif // OPENCVIMAGEPROVIDER_H
