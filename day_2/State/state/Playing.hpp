#pragma once
#include "MusicPlayer.hpp"


// Concrete State: Playing
class Playing : public State {
public:
    Playing(MusicPlayer& player) : player(player) {}

    void entry() override {
        std::cout << "Entering 'playing' state\n";
        player.playMusic();
    }

    void exit() override {
        std::cout << "Exiting 'playing' state\n";
    }

    void handle(Event event, MusicPlayer& player) override;

private:
    MusicPlayer& player;
};
