#pragma once

#include <unordered_set>
#include "Channel.hpp"

namespace streaming_platform {

    class StreamingPlatform {

    public:
        using Channels = std::unordered_set<Channel::Shared>;
        using SubScribers = std::unordered_set<SubScriber::Shared>;

        StreamingPlatform() = default;

        Channel& create_channel(const std::string& name);
        SubScriber& create_subscriber(const std::string& name);

        auto channels() const -> const Channels& { return m_channels; }
        auto subscribers() const -> const SubScribers& { return m_subscribers; }
    private:

        Channels m_channels;
        SubScribers m_subscribers;
    };

    void main();
}