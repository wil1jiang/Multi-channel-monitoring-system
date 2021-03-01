#pragma once
#include <vector>
#include <mutex>
struct XCameraData
{
    char name[1024] = { 0 };
    char url[4096] = { 0 };         //摄像机主码流
    char sub_url[4096] = { 0 };     //摄像机辅码流
    char save_path[4096] = { 0 };   //视频录制存放目录
};

class XCameraConfig
{
public:

    //唯一对象实例 单件模式
    static XCameraConfig* Instance()
    {
        static XCameraConfig xc;
        return &xc;
    }
    //插入摄像机 线程安全
    void Push(const XCameraData& data);

    /// <summary>
    /// 获取摄像头
    /// </summary>
    /// <param name="index">摄像头索引 从0开始</param>
    /// <returns>返回空对象，可以判断name为空字符串</returns>
    XCameraData GetCam(int index);


    /// <summary>
    /// 修改摄像机数据
    /// </summary>
    /// <param name="index"></param>
    /// <param name="data"></param>
    /// <returns></returns>
    bool SetCam(int index, const XCameraData& data);

    bool DelCam(int index);

    /// <summary>
    /// 获取相机数量
    /// </summary>
    /// <returns>失败返回0</returns>
    int GetCamCount();

    /// <summary>
    /// 存储配置文件
    /// </summary>
    /// <param name="path"></param>
    /// <returns></returns>
    bool Save(const char* path);


    /// <summary>
    /// 读取配置 存入cams_
    /// </summary>
    /// <param name="path"></param>
    /// <returns></returns>
    bool Load(const char* path);
private:
    XCameraConfig() {}//构造私有 单件模式
    std::vector<XCameraData> cams_;
    std::mutex mux_;
};

