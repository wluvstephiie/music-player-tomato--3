#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>

class Player {
public:
    enum class PlayState {
        STOPPED,
        PLAYING,
        PAUSED
    };

    Player();
    ~Player();

    // Playback control
    void play(const std::string& filepath);
    void pause();
    void resume();
    void stop();
    void seek(double seconds);

    // Volume control
    void setVolume(float volume);  // 0.0 to 1.0
    float getVolume() const;

    // Status
    PlayState getState() const;
    double getCurrentTime() const;
    double getDuration() const;
    std::string getCurrentFile() const;
    bool isPlaying() const;

private:
    PlayState state;
    float volume;
    std::string currentFile;
    double currentTime;
    double duration;
};

#endif // PLAYER_H
