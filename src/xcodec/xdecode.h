#pragma once
#include "xcodec.h"
struct AVBufferRef;
class XCODEC_API XDecode :public XCodec
{
public:
    bool Send(const AVPacket* pkt);  //发送解码
    bool Recv(AVFrame* frame);       //获取解码
    std::vector<AVFrame*> End();    //获取缓存

    bool InitHW(int type = 4);

};

