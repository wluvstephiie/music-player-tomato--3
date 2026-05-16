#include "playlist.h"
#include <algorithm>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

Playlist::Playlist() 
    : currentIndex(0), shuffle(false), loop(false) {}

Playlist::~Playlist() {}

void Playlist::loadFromDirectory(const std::string& directory) {
    clear();
    
    try {
        for (const auto& entry : fs::directory_iterator(directory)) {
            if (entry.is_regular_file() && isMusicFile(entry.path().string())) {
                addTrack(entry.path().string());
            }
        }
        std::sort(tracks.begin(), tracks.end());
        std::cout << "Loaded " << tracks.size() << " tracks" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error loading directory: " << e.what() << std::endl;
    }
}

void Playlist::addTrack(const std::string& filepath) {
    tracks.push_back(filepath);
}

void Playlist::removeTrack(int index) {
    if (index >= 0 && index < static_cast<int>(tracks.size())) {
        tracks.erase(tracks.begin() + index);
        if (currentIndex >= static_cast<int>(tracks.size())) {
            currentIndex = tracks.size() - 1;
        }
    }
}

void Playlist::clear() {
    tracks.clear();
    currentIndex = 0;
}

std::string Playlist::getCurrentTrack() const {
    if (currentIndex >= 0 && currentIndex < static_cast<int>(tracks.size())) {
        return tracks[currentIndex];
    }
    return "";
}

std::string Playlist::getNextTrack() {
    if (tracks.empty()) return "";
    
    currentIndex = (currentIndex + 1) % tracks.size();
    return getCurrentTrack();
}

std::string Playlist::getPreviousTrack() {
    if (tracks.empty()) return "";
    
    currentIndex = (currentIndex - 1 + tracks.size()) % tracks.size();
    return getCurrentTrack();
}

void Playlist::setCurrentIndex(int index) {
    if (index >= 0 && index < static_cast<int>(tracks.size())) {
        currentIndex = index;
    }
}

int Playlist::getCurrentIndex() const {
    return currentIndex;
}

int Playlist::getTrackCount() const {
    return tracks.size();
}

std::vector<std::string> Playlist::getAllTracks() const {
    return tracks;
}

bool Playlist::isEmpty() const {
    return tracks.empty();
}

void Playlist::setShuffle(bool enabled) {
    shuffle = enabled;
}

void Playlist::setLoop(bool enabled) {
    loop = enabled;
}

bool Playlist::isShuffleEnabled() const {
    return shuffle;
}

bool Playlist::isLoopEnabled() const {
    return loop;
}

bool Playlist::isMusicFile(const std::string& filename) const {
    std::string ext = fs::path(filename).extension().string();
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    return ext == ".mp3" || ext == ".wav" || ext == ".flac" || ext == ".ogg";
}
