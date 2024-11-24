#pragma once
#include "Inactive.hpp"
#include "On.hpp"

void Inactive::handle(Event event, MusicPlayer& player) {
    if (event == Event::OnOffPressed) {
        player.setState(new On(player));
        std::cout << "OnOffPressed event in 'on' state\n";
    }
}
