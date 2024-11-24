#pragma once
#include "MusicPlayer.hpp"

// Concrete State: Paused
class Paused : public State {
public:
    Paused(MusicPlayer& player) : player(player) {}

    void entry() override {
        std::cout << "Entering 'pausing' state\n";
        player.pauseMusic();
    }

    void exit() override {
        std::cout << "Exiting 'pausing' state\n";
    }

    void handle(Event event, MusicPlayer& player) override;

private:
    MusicPlayer& player;
};
