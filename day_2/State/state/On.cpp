#pragma once
#include "On.hpp"
#include "Playing.hpp"
#include "Inactive.hpp"

void On::handle(Event event, MusicPlayer& player) {
    if (event == Event::PlayPausePressed) {
        player.setState(new Playing(player));
        std::cout << "PlayPausePressed event in 'playing' state\n";
    }
    else if (event == Event::OnOffPressed) {
        player.setState(new Inactive(player));
        std::cout << "PlayPausePressed event in 'inactive' state\n";
    }
}

