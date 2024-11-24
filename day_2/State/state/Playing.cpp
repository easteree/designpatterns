#pragma once
#include "Playing.hpp"
#include "Paused.hpp"
#include "Inactive.hpp"

void Playing::handle(Event event, MusicPlayer& player) {
    if (event == Event::PlayPausePressed) {
        std::cout << "PlayPausePressed event in 'pausing' state\n";
        player.setState(new Paused(player));
    }
    else if (event == Event::OnOffPressed) {
        player.setState(new Inactive(player));
        std::cout << "PlayPausePressed event in 'inactive' state\n";
    }
}
