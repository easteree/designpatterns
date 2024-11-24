#pragma once
#include <iostream>
#include "state/State.hpp"

// Context class (MusicPlayer)
class MusicPlayer {
public:
    MusicPlayer();

    ~MusicPlayer();

    bool is_on() const;

    void setState(State* new_state);

    void turnLedOn() {
        led_on = true;
        std::cout << "LED on" << std::endl;//🌕
    }

    void turnLedOff() {
        led_on = false;
        std::cout << "LED off" << std::endl;
    }

    void playMusic() {
        std::cout << "Music playing" << std::endl;//🔊
    }

    void pauseMusic() {
        std::cout << "Music paused" << std::endl;//🔇
    }

    void handle(Event event);

private:
    State* state;
    bool led_on;
};

