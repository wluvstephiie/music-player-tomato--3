# Music Player Tomato 🍅🎵

A lightweight, feature-rich terminal music player built with C++.

## Features

- 🎵 Play MP3, WAV, and FLAC audio files
- 🎮 Interactive terminal UI with keyboard controls
- 📋 Playlist management with shuffle and loop modes
- 🔊 Volume control
- ⏱️ Progress bar and time tracking
- 🎨 Beautiful ncurses-based interface
- 📂 Load entire directories of music files

## Requirements

- C++17 or higher
- CMake 3.10+
- ncurses library
- libmpg123 (for MP3 support)
- libsndfile (for WAV/FLAC support)
- PortAudio (for audio output)

## Installation

### Ubuntu/Debian
```bash
sudo apt-get install libncurses-dev libmpg123-dev libsndfile1-dev portaudio19-dev cmake
```

### macOS
```bash
brew install ncurses mpg123 libsndfile portaudio cmake
```

## Building

```bash
git clone https://github.com/wluvstephiie/music-player-tomato--3.git
cd music-player-tomato--3
mkdir build
cd build
cmake ..
make
```

## Usage

```bash
./music-player [path/to/music/directory]
```

If no directory is specified, it defaults to `./music`.

### Keyboard Controls

| Key | Action |
|-----|--------|
| `Space` | Play/Pause |
| `N` | Next track |
| `P` | Previous track |
| `+` | Volume up |
| `-` | Volume down |
| `L` | Toggle loop mode |
| `S` | Toggle shuffle mode |
| `→` | Seek forward 5 seconds |
| `←` | Seek backward 5 seconds |
| `↑` / `↓` | Scroll playlist |
| `Q` | Quit |

## Project Structure

```
music-player-tomato--3/
├── src/
│   ├── main.cpp           # Entry point
│   ├── player.h           # Audio player class declaration
│   ├── player.cpp         # Audio player implementation
│   ├── playlist.h         # Playlist management
│   ├── playlist.cpp       # Playlist implementation
│   ├── ui.h               # Terminal UI declaration
│   ├── ui.cpp             # Terminal UI implementation
│   └── audio.h            # Audio utility functions
├── CMakeLists.txt         # Build configuration
├── .gitignore             # Git ignore file
└── README.md              # This file
```

## Architecture

### Player (player.h/cpp)
Handles:
- Audio file loading and decoding
- Playback control (play, pause, seek)
- Volume management
- Currently playing track info

### Playlist (playlist.h/cpp)
Manages:
- Track list from directory
- Track navigation (next, previous)
- Shuffle and loop modes
- Playlist state

### UI (ui.h/cpp)
Provides:
- ncurses terminal interface
- Keyboard input handling
- Display of current track info
- Progress bar visualization
- Playlist display

## Future Enhancements

- [ ] Metadata reading (artist, album, title)
- [ ] Album art display
- [ ] Equalizer controls
- [ ] Playlist file support (.m3u, .pls)
- [ ] Search and filter functionality
- [ ] Configuration file support
- [ ] Themes/color customization
- [ ] Persistent playback history

## License

MIT License - See LICENSE file for details

## Contributing

Contributions are welcome! Feel free to:
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

## Author

Created by [@wluvstephiie](https://github.com/wluvstephiie)
