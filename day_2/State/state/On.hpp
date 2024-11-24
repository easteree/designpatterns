#pragma once
#include "MusicPlayer.hpp"

// Concrete State: On
class On : public State {
public:
    On(MusicPlayer& player) : player(player) {}

    void entry() override {
        std::cout << "Entering 'on' state\n";
        player.turnLedOn();
    }

    void exit() override {
        std::cout << "Exiting 'on' state\n";
    }

    void handle(Event event, MusicPlayer& player) override;

private:
    MusicPlayer& player;
};


