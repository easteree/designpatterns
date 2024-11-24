#include <iostream>
#include <unordered_map>
#include "MusicPlayer.hpp"

// Main function
int main() {
    MusicPlayer player;

    std::unordered_map<char, Event> menu = {
        {'1', Event::OnOffPressed},
        {'2', Event::PlayPausePressed}
    };

    char choice = '0';
    do{
        std::cout << "Press a button:\n";
        std::cout << "1. On / Off\n";
        std::cout << "2. Play / Pause\n";
        std::cout << "Choice: ";

        std::cin >> choice;

        if (menu.find(choice) != menu.end()) {
            player.handle(menu[choice]);
        } else {
            std::cout << "Invalid choice.\n";
            continue;
        }
        std::cout << "\n";
    }while (player.is_on());

    return 0;
}
