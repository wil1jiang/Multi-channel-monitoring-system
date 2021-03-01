#include "xviewer.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QDir>
#include "xcamera_config.h"
#define TEST_CAM_PATH "test.db"
#include "xcamera_record.h"
int main(int argc, char *argv[])
{
    const char* save_path = "./video/0/";
    QDir dir;
    dir.mkpath(save_path);

    XCameraRecord xr;
    xr.set_rtsp_url(
        "rtsp://test:x12345678@192.168.2.64/h264/ch1/main/av_stream");
    xr.set_save_path(save_path);
    xr.Start();


    /*auto* xc = XCameraConfig::Instance();
    xc->Load(TEST_CAM_PATH);
    {
        XCameraData cd;
        strcpy(cd.name, "camera1");
        strcpy(cd.save_path, ".\\camera1\\");
        strcpy(cd.url, 
            "rtsp://test:x12345678@192.168.2.64/h264/ch1/main/av_stream");
        strcpy(cd.sub_url,
            "rtsp://test:x12345678@192.168.2.64/h264/ch1/sub/av_stream");
        xc->Push(cd);
    }
    {
        XCameraData cd;
        strcpy(cd.name, "camera2");
        strcpy(cd.save_path, ".\\camera2\\");
        strcpy(cd.url,
            "rtsp://admin:admin@192.168.2.108/cam/realmonitor?channel=1&subtype=0");
        strcpy(cd.sub_url,
            "rtsp://admin:admin@192.168.2.108/cam/realmonitor?channel=1&subtype=1");
        xc->Push(cd);
    }
    int cam_count = xc->GetCamCount();
    for (int i = 0; i < cam_count; i++)
    {
        auto cam = xc->GetCam(i);
        qDebug() << cam.name;
    }
    qDebug() << "=================Set=====================";
    auto d1 = xc->GetCam(0);
    strcpy(d1.name, "camera_001");
    xc->SetCam(0, d1);
    cam_count = xc->GetCamCount();
    for (int i = 0; i < cam_count; i++)
    {
        auto cam = xc->GetCam(i);
        qDebug() << cam.name;
    }

    xc->Save(TEST_CAM_PATH);


    qDebug() << "=================Del=====================";
    xc->DelCam(1);
    cam_count = xc->GetCamCount();
    for (int i = 0; i < cam_count; i++)
    {
        auto cam = xc->GetCam(i);
        qDebug() << cam.name;
    }
    xc->DelCam(0);*/

    QApplication a(argc, argv);
    XViewer w;
    w.show();
    auto re = a.exec();
    xr.Stop();
    return re;
}
