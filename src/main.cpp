#include <iostream>
#include <string>
#include <filesystem>
#include "player.h"
#include "playlist.h"
#include "ui.h"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    std::string musicDir = "./music";
    
    if (argc > 1) {
        musicDir = argv[1];
    }

    // Check if directory exists
    if (!fs::exists(musicDir)) {
        std::cerr << "Error: Directory '" << musicDir << "' does not exist!" << std::endl;
        std::cerr << "Usage: " << argv[0] << " [path/to/music/directory]" << std::endl;
        return 1;
    }

    try {
        Player player;
        Playlist playlist;
        UI ui;

        // Load music from directory
        playlist.loadFromDirectory(musicDir);

        if (playlist.isEmpty()) {
            std::cerr << "No music files found in '" << musicDir << "'" << std::endl;
            return 1;
        }

        // Initialize UI
        ui.init();

        bool running = true;
        int selectedTrack = 0;

        while (running) {
            ui.displayMenu(playlist, player);

            int input = ui.handleInput();
            switch (input) {
                case ' ':  // Space - Play/Pause
                    if (player.isPlaying()) {
                        player.pause();
                    } else {
                        if (player.getState() == Player::PlayState::STOPPED) {
                            player.play(playlist.getCurrentTrack());
                        } else {
                            player.resume();
                        }
                    }
                    break;

                case 'n':  // Next track
                case 'N':
                    playlist.getNextTrack();
                    selectedTrack = playlist.getCurrentIndex();
                    if (player.isPlaying()) {
                        player.play(playlist.getCurrentTrack());
                    }
                    break;

                case 'p':  // Previous track
                case 'P':
                    playlist.getPreviousTrack();
                    selectedTrack = playlist.getCurrentIndex();
                    if (player.isPlaying()) {
                        player.play(playlist.getCurrentTrack());
                    }
                    break;

                case '+':  // Volume up
                    player.setVolume(player.getVolume() + 0.05f);
                    break;

                case '-':  // Volume down
                    player.setVolume(player.getVolume() - 0.05f);
                    break;

                case 'l':  // Loop
                case 'L':
                    playlist.setLoop(!playlist.isLoopEnabled());
                    break;

                case 's':  // Shuffle
                case 'S':
                    playlist.setShuffle(!playlist.isShuffleEnabled());
                    break;

                case 'q':  // Quit
                case 'Q':
                    running = false;
                    break;

                case KEY_UP:  // Scroll up in playlist
                    if (selectedTrack > 0) {
                        selectedTrack--;
                        playlist.setCurrentIndex(selectedTrack);
                    }
                    break;

                case KEY_DOWN:  // Scroll down in playlist
                    if (selectedTrack < playlist.getTrackCount() - 1) {
                        selectedTrack++;
                        playlist.setCurrentIndex(selectedTrack);
                    }
                    break;

                case KEY_ENTER:  // Play selected track
                    player.play(playlist.getCurrentTrack());
                    break;
            }
        }

        ui.cleanup();
        std::cout << "\nThank you for using Music Player!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
