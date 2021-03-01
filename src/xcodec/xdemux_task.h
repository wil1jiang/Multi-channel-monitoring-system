#pragma once
#include "xtools.h"
#include "xdemux.h"
class XCODEC_API XDemuxTask :public XThread
{
public:
    void Main();
    /// <summary>
    /// �򿪽��װ
    /// </summary>
    /// <param name="url">rtsp��ַ</param>
    /// <param name="timeout_ms">��ʱʱ�� ��λ����</param>
    /// <returns></returns>
    bool Open(std::string url,int timeout_ms = 1000);

    //������Ƶ����
    std::shared_ptr<XPara> CopyVideoPara()
    {
        return demux_.CopyVideoPara();
    }
    std::shared_ptr<XPara> CopyAudioPara()
    {
        return demux_.CopyAudioPara();
    }
private:
    XDemux demux_;
    std::string url_;
    int timeout_ms_ = 0;//��ʱʱ��
};

