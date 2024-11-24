#include "StreamingPlatform.hpp"

namespace streaming_platform {

    Channel& StreamingPlatform::create_channel(const std::string& name)
    {
        auto ch = Channel::create(name);
        m_channels.insert(ch);
        return *ch;
    }

    SubScriber& StreamingPlatform::create_subscriber(const std::string& name)
    {
        auto sub = SubScriber::create(name);
        m_subscribers.insert(sub);
        return *sub;
    }

    void main() {
        StreamingPlatform platform{};

        auto& ch_workshop = platform.create_channel("workshop");

        auto& sub_tim = platform.create_subscriber("Tim");
        sub_tim.follow(ch_workshop);

        ch_workshop.upload(Video{ "wood work" });

        auto& sub_susan = platform.create_subscriber("Susan");
        sub_susan.follow(ch_workshop);

        auto& ch_fun = platform.create_channel("fun");
        ch_fun.subscribe(sub_susan);

        ch_fun.upload(Video{ "happy dance" });
        ch_workshop.upload(Video{ "metal work" });
        ch_fun.upload(Video{ "cat & piano" });
        ch_workshop.upload(Video{ "glas work" });
    }

}