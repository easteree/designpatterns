#pragma once

#include <unordered_map>
#include "Video.hpp"

namespace streaming_platform {

    class SubScriber;

    class Channel {
        Channel();
    public:
        using Shared = std::shared_ptr<Channel>;

        static auto create(const std::string& name) -> Shared;
        auto make_shared()->Shared;
        auto name() const { return m_name; }

        void upload(Video video);

        void subscribe(SubScriber& subscriber);
        void unsubscribe(SubScriber& subscriber);
        void notify();

        auto id() const { return m_id; }

        ~Channel();
    private:
        std::weak_ptr<Channel> m_self;
        std::uint64_t m_id;
        std::string m_name;

        std::unordered_map<std::uint64_t, std::weak_ptr<SubScriber>> m_subscribers;

        std::list<Video> m_videos_archive, m_videos_uploaded;
    };
}

#include "SubScriber.hpp"
