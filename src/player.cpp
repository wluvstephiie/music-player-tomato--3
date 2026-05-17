#include "player.h"
#include <iostream>
#include <cstdlib>

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
    duration = 0.0;

    std::cout << "Playing: " << filepath << std::endl;

    std::string command =
        "ffplay -nodisp -autoexit \"" +
        filepath +
        "\" >/dev/null 2>&1 &";

    system(command.c_str());
}
