#include <iostream>
#include "Channel.hpp"

namespace {
    std::uint64_t next_channel_id = 0u;
}

namespace streaming_platform {

    Channel::Channel() : m_id{ next_channel_id++ } {

    }

    auto Channel::create(const std::string& name) -> Shared
    {
        auto channel = Shared(new Channel());
        channel->m_name = name;
        channel->m_self = channel;
        return channel;
    }

    auto Channel::make_shared() -> Shared
    {
        return m_self.lock();
    }

    void Channel::upload(Video video)
    {
        std::cout << "Channel: \"" << name() << "\" has new Video \"" << video.name << "\"" << std::endl;
        m_videos_uploaded.push_back(video);
        notify();
    }

    void Channel::subscribe(SubScriber& subscriber)
    {
        if (m_subscribers.find(subscriber.id()) != m_subscribers.end()) return;

        std::cout << "Channel: \"" << name() << "\" has a new SubScriber \"" << subscriber.name() << "\"" << std::endl;
        m_subscribers.insert({ subscriber.id(), subscriber.make_shared() });
        subscriber.follow(*this);
    }

    void Channel::unsubscribe(SubScriber& subscriber)
    {
        auto it = m_subscribers.find(subscriber.id());
        if (it == m_subscribers.end()) return;

        std::cout << "Channel: \"" << name() << "\" has lost SubScriber \"" << subscriber.name() << "\"" << std::endl;
        m_subscribers.erase(it);
        subscriber.unfollow(*this);
    }

    void Channel::notify()
    {
        decltype(m_videos_uploaded) videos;
        std::swap(videos, m_videos_uploaded);

        for (auto& video : videos) {
            for (auto& [id,subscriber] : m_subscribers) {
                auto sub = subscriber.lock();
                if (!sub) continue;
                sub->notified(*this,video);
            }
            m_videos_archive.push_back(video);
        }
    }

    Channel::~Channel()
    {
        while (m_subscribers.size()) {
            auto it = m_subscribers.begin();
            auto sub = it->second.lock();
            if (sub) {
                sub->unfollow(*this);
                unsubscribe(*sub);
            }
            else {
                m_subscribers.erase(it);
            }
        }
    }
}