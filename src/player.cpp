#include "player.h"
#include <iostream>

Player::Player() 
    : state(PlayState::STOPPED), 
      volume(0.7f), 
      currentTime(0.0), 
      duration(0.0) {}

Player::~Player() {
    if (state != PlayState::STOPPED) {
        stop();
    }
}

void Player::play(const std::string& filepath) {
    currentFile = filepath;
    state = PlayState::PLAYING;
    currentTime = 0.0;
    duration = 0.0;  // In a real implementation, you'd load the file duration
    std::cout << "Playing: " << filepath << std::endl;
}

void Player::pause() {
    if (state == PlayState::PLAYING) {
        state = PlayState::PAUSED;
    }
}

void Player::resume() {
    if (state == PlayState::PAUSED) {
        state = PlayState::PLAYING;
    }
}

void Player::stop() {
    state = PlayState::STOPPED;
    currentTime = 0.0;
    duration = 0.0;
}

void Player::seek(double seconds) {
    if (seconds >= 0 && seconds <= duration) {
        currentTime = seconds;
    }
}

void Player::setVolume(float vol) {
    if (vol >= 0.0f && vol <= 1.0f) {
        volume = vol;
    }
}

float Player::getVolume() const {
    return volume;
}

Player::PlayState Player::getState() const {
    return state;
}

double Player::getCurrentTime() const {
    return currentTime;
}

double Player::getDuration() const {
    return duration;
}

std::string Player::getCurrentFile() const {
    return currentFile;
}

bool Player::isPlaying() const {
    return state == PlayState::PLAYING;
}
