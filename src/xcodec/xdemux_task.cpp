#include "xdemux_task.h"
extern "C"
{
#include <libavformat/avformat.h>
}
using namespace std;
bool XDemuxTask::Open(std::string url, int timeout_ms)
{
 
    LOGDEBUG("XDemuxTask::Open begin!");
    demux_.set_c(nullptr);//断开之前的连接
    this->url_ = url;
    this->timeout_ms_ = timeout_ms;
    auto c = demux_.Open(url.c_str());
    if (!c)return false;
    demux_.set_c(c);
    demux_.set_time_out_ms(timeout_ms);
    LOGDEBUG("XDemuxTask::Open end!");
    return true;
}
void XDemuxTask::Main()
{
    AVPacket pkt;
    while (!is_exit_)
    {
        if (!demux_.Read(&pkt))
        {
            //读取失败
            cout << "-" << flush;
            if (!demux_.is_connected())
            {
                Open(url_, timeout_ms_);
            }

            this_thread::sleep_for(1ms);
            continue;
        }
        cout << "." << flush;
        Next(&pkt);
        av_packet_unref(&pkt);

        this_thread::sleep_for(1ms);
    }
}