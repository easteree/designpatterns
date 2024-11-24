#pragma once
// Events for state transitions
enum class Event {
    OnOffPressed,
    PlayPausePressed
};

// Abstract State class
class State {
public:
    virtual ~State() = default;

    virtual void entry() = 0;  // Entering the state
    virtual void exit() = 0;   // Exiting the state
    virtual void handle(Event event, class MusicPlayer& player) = 0;  // Handling events
};