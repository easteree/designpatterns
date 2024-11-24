#pragma once

#include "Video.hpp"

namespace streaming_platform {
    class Channel;

    class ChannelNotification {
    public:
        virtual void notified(const Channel& channel, const Video& video) = 0;
        virtual ~ChannelNotification() = default;
    };

}
