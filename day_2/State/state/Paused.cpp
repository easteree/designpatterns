#include "Paused.hpp"
#include "Playing.hpp"
#include "Inactive.hpp"


void Paused::handle(Event event, MusicPlayer& player) {
    if (event == Event::PlayPausePressed) {
        std::cout << "PlayPausePressed event in 'playing' state\n";
        State* state = new Playing(player);
        player.setState(state);
    }
    else if (event == Event::OnOffPressed) {
        player.setState(new Inactive(player));
        std::cout << "PlayPausePressed event in 'inactive' state\n";
    }
}
