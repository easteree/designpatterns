#include <iostream>
#include "SubScriber.hpp"

namespace {
    std::uint64_t next_subscriber_id = 0u;
}

namespace streaming_platform {

    SubScriber::SubScriber() : m_id{ next_subscriber_id++ } {

    }

    auto SubScriber::create(const std::string& name) -> Shared
    {
        auto subscriber = Shared(new SubScriber());
        subscriber->m_name = name;
        subscriber->m_self = subscriber;
        return subscriber;
    }
    auto SubScriber::make_shared()->Shared {
        return m_self.lock();
    }

    void SubScriber::notified(const Channel& channel, const Video& video)
    {
        std::cout << "Subscriber: \"" << name() << "\" is notified: Video \"" << video.name << "\" @ Channel \"" << channel.name() << "\"" << std::endl;
    }

    void SubScriber::follow(Channel& channel)
    {
        if (m_channels.find(channel.id()) != m_channels.end()) return;

        std::cout << "Subscriber: \"" << name() << "\" follows Channel \"" << channel.name() << "\"" << std::endl;
        m_channels.insert({ channel.id(),channel.make_shared() });
        channel.subscribe(*this);
    }

    void SubScriber::unfollow(Channel& channel)
    {
        auto it = m_channels.find(channel.id());
        if (it == m_channels.end()) return;

        std::cout << "Subscriber: \"" << name() << "\" unfollows Channel \"" << channel.name() << "\"" << std::endl;
        m_channels.erase(it);
        channel.unsubscribe(*this);
    }

    SubScriber::~SubScriber()
    {
        while (m_channels.size()) {
            auto it = m_channels.begin();
            auto ch = it->second.lock();
            if (ch) {
                ch->unsubscribe(*this);
                unfollow(*ch);
            }
            else {
                m_channels.erase(it);
            }
        }
    }
}
