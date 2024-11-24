#include "MusicPlayer.hpp"
#include "state/Inactive.hpp"
// MusicPlayer Implementation
MusicPlayer::MusicPlayer() : state(new Inactive(*this)), led_on(false) {
}

MusicPlayer::~MusicPlayer() {
    delete state;
}

bool MusicPlayer::is_on() const
{
    const auto inactive=dynamic_cast<Inactive*>(state);
    return (inactive==nullptr);
}

void MusicPlayer::setState(State* new_state) {
    state->exit();
    delete state;
    state = new_state;
    state->entry();
}

void MusicPlayer::handle(Event event) {
    state->handle(event, *this);
}
