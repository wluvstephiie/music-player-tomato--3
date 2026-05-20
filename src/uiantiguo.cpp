//Todas estas lineas de codigo son de un archivo que ya no uso porque se crashea constantemente, si quieres usarlo de ejercico esta el error comentado en notas//

/*#include "ui.h"
#include <cmath>
#include <iomanip>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

UI::UI() : playlistWindow(nullptr), playerWindow(nullptr), statusWindow(nullptr) {}

UI::~UI() {
    cleanup();
}

void UI::init() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);  // Hide cursor

    getmaxyx(stdscr, maxY, maxX);

    // Create windows
    playlistWindow = newwin(maxY - 5, maxX, 0, 0);
    playerWindow = newwin(3, maxX, maxY - 5, 0);
    statusWindow = newwin(2, maxX, maxY - 2, 0);

    // Enable scrolling
    scrollok(playlistWindow, TRUE);
}

void UI::cleanup() {
    if (playlistWindow) delwin(playlistWindow);
    if (playerWindow) delwin(playerWindow);
    if (statusWindow) delwin(statusWindow);
    endwin();
}

void UI::displayMenu(const Playlist& playlist, const Player& player) {
    clear(); // Este es el error porque se reinicia contstantemente
    refresh(); // el refresh solo lo vuelve a recargar cada vez que se sube

    displayPlaylist(playlist, playlist.getCurrentIndex());
    displayNowPlaying(player.getCurrentFile(), player);
    displayStatus(player, playlist);
}

int UI::handleInput() {
    int ch = getch();
    return ch;
}

void UI::displayPlaylist(const Playlist& playlist, int selectedIndex) {
    werase(playlistWindow);
    box(playlistWindow, 0, 0);
    mvwaddstr(playlistWindow, 0, 2, " Playlist ");

    std::vector<std::string> tracks = playlist.getAllTracks();
    for (int i = 0; i < static_cast<int>(tracks.size()) && i < maxY - 7; i++) {
        std::string filename = getFileName(tracks[i]);
        if (i == selectedIndex) {
            wattron(playlistWindow, A_REVERSE);
            mvwaddstr(playlistWindow, i + 1, 2, filename.c_str());
            wattroff(playlistWindow, A_REVERSE);
        } else {
            mvwaddstr(playlistWindow, i + 1, 2, filename.c_str());
        }
    }
    wrefresh(playlistWindow);
}

void UI::displayNowPlaying(const std::string& filename, const Player& player) {
    werase(playerWindow);
    box(playerWindow, 0, 0);
    mvwaddstr(playerWindow, 0, 2, " Now Playing ");

    if (!filename.empty()) {
        std::string name = getFileName(filename);
        mvwaddstr(playerWindow, 1, 2, name.c_str());
        displayProgressBar(player.getCurrentTime(), player.getDuration());
    }
    wrefresh(playerWindow);
}

void UI::displayProgressBar(double current, double duration) {
    int barWidth = maxX - 6;
    double progress = duration > 0 ? current / duration : 0.0;
    int filledWidth = static_cast<int>(progress * barWidth);

    std::string bar = "[";
    for (int i = 0; i < barWidth; i++) {
        bar += (i < filledWidth) ? "=" : "-";
    }
    bar += "]";

    mvwaddstr(playerWindow, 2, 2, bar.c_str());
    mvwprintw(playerWindow, 2, barWidth + 4, "%s / %s",
              formatTime(current).c_str(),
              formatTime(duration).c_str());
}

void UI::displayStatus(const Player& player, const Playlist& playlist) {
    werase(statusWindow);
    box(statusWindow, 0, 0);

    std::string status = "Status: ";
    switch (player.getState()) {
        case Player::PlayState::PLAYING:
            status += "Playing";
            break;
        case Player::PlayState::PAUSED:
            status += "Paused";
            break;
        case Player::PlayState::STOPPED:
            status += "Stopped";
            break;
    }

    status += " | Vol: " + std::to_string(static_cast<int>(player.getVolume() * 100)) + "%";
    if (playlist.isShuffleEnabled()) status += " | Shuffle: ON";
    if (playlist.isLoopEnabled()) status += " | Loop: ON";

    mvwaddstr(statusWindow, 1, 2, status.c_str());
    mvwaddstr(statusWindow, 1, maxX - 40, "Commands: [SPACE]Play/Pause [N]ext [P]rev [Q]uit");

    wrefresh(statusWindow);
}

void UI::displayMessage(const std::string& message) {
    mvwaddstr(statusWindow, 0, 2, message.c_str());
    wrefresh(statusWindow);
}

std::string UI::formatTime(double seconds) {
    int mins = static_cast<int>(seconds) / 60;
    int secs = static_cast<int>(seconds) % 60;

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << mins << ":" 
        << std::setfill('0') << std::setw(2) << secs;
    return oss.str();
}

std::string UI::getFileName(const std::string& fullPath) {
    return fs::path(fullPath).filename().string();
}
*/ 
