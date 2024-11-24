#pragma once

#include <unordered_map>
#include "ChannelNotification.hpp"

namespace streaming_platform {

    class SubScriber : public ChannelNotification {
        SubScriber();
    public:
        using Shared = std::shared_ptr<SubScriber>;

        static auto create(const std::string& name)->Shared;
        auto make_shared() -> Shared;
        auto name() const { return m_name; }

        void follow(Channel& channel);
        void unfollow(Channel& channel);

        auto id() const { return m_id; }

        ~SubScriber();

    public://ChannelNotification
        void notified(const Channel& channel, const Video& video) override;

    private:
        std::weak_ptr<SubScriber> m_self;
        std::uint64_t m_id;
        std::string m_name;

        std::unordered_map<std::uint64_t, std::weak_ptr<Channel>> m_channels;
    };

}

#include "Channel.hpp"
