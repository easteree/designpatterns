#pragma once
#include "MusicPlayer.hpp"

// Concrete State: Inactive
class Inactive : public State {
public:
    Inactive(MusicPlayer& player) : player(player) {}

    void entry() override {
        std::cout << "Entering 'inactive' state\n";
        player.turnLedOff();
    }

    void exit() override {
        std::cout << "Exiting 'inactive' state\n";
    }

    void handle(Event event, MusicPlayer& player) override;

private:
    MusicPlayer& player;
};
