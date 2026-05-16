#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include <filesystem>

class Playlist {
public:
    Playlist();
    ~Playlist();

    // Load music from directory
    void loadFromDirectory(const std::string& directory);
    
    // Playlist control
    void addTrack(const std::string& filepath);
    void removeTrack(int index);
    void clear();

    // Navigation
    std::string getCurrentTrack() const;
    std::string getNextTrack();
    std::string getPreviousTrack();
    void setCurrentIndex(int index);

    // Status
    int getCurrentIndex() const;
    int getTrackCount() const;
    std::vector<std::string> getAllTracks() const;
    bool isEmpty() const;

    // Shuffle and loop modes
    void setShuffle(bool enabled);
    void setLoop(bool enabled);
    bool isShuffleEnabled() const;
    bool isLoopEnabled() const;

private:
    std::vector<std::string> tracks;
    int currentIndex;
    bool shuffle;
    bool loop;

    bool isMusicFile(const std::string& filename) const;
};

#endif // PLAYLIST_H
