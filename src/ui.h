#ifndef UI_H
#define UI_H

#include <ncurses.h>
#include <string>
#include <vector>
#include "player.h"
#include "playlist.h"

class UI {
public:
    UI();
    ~UI();

    void init();
    void cleanup();
    void displayMenu(const Playlist& playlist, const Player& player);
    int handleInput();
    void displayPlaylist(const Playlist& playlist, int selectedIndex);
    void displayNowPlaying(const std::string& filename, 
                          const Player& player);
    void displayProgressBar(double current, double duration);
    void displayStatus(const Player& player, const Playlist& playlist);
    void displayMessage(const std::string& message);

private:
    int maxX, maxY;
    WINDOW* playlistWindow;
    WINDOW* playerWindow;
    WINDOW* statusWindow;

    std::string formatTime(double seconds);
    std::string getFileName(const std::string& fullPath);
};

#endif // UI_H
