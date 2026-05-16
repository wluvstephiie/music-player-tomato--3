# 🎵 Terminal Music Player

A lightweight, feature-rich music player for your terminal built with C++.

## Features

- 🎵 **Play multiple audio formats** - MP3, WAV, FLAC, OGG
- 🎮 **Interactive Terminal UI** - Beautiful ncurses-based interface
- 📋 **Playlist Management** - Load entire music directories
- 🔊 **Volume Control** - Adjust volume on the fly
- ⏱️ **Progress Tracking** - Visual progress bar and time display
- 🎨 **Shuffle & Loop** - Customize playback modes
- ⌨️ **Keyboard Controls** - Intuitive key bindings

## Requirements

- **C++17** or higher
- **CMake 3.10+**
- **ncurses** library
- **GCC** or **Clang** compiler

### Install Dependencies

**Ubuntu/Debian:**
```bash
sudo apt-get install libncurses-dev build-essential cmake
```

**macOS:**
```bash
brew install ncurses cmake
```

**Fedora/RHEL:**
```bash
sudo dnf install ncurses-devel cmake gcc-c++
```

## Building

```bash
# Clone the repository
git clone https://github.com/wluvstephiie/music-player-tomato--3.git
cd music-player-tomato--3

# Create build directory
mkdir build
cd build

# Build with CMake
cmake ..
make
```

## Usage

```bash
# Run with default music directory (./music)
./music-player

# Run with custom music directory
./music-player /path/to/your/music
```

### Keyboard Controls

| Key | Action |
|-----|--------|
| `Space` | Play/Pause |
| `N` | Next Track |
| `P` | Previous Track |
| `+` / `-` | Volume Up/Down |
| `L` | Toggle Loop Mode |
| `S` | Toggle Shuffle Mode |
| `↑` / `↓` | Navigate Playlist |
| `Enter` | Play Selected Track |
| `Q` | Quit |

## Project Structure

```
music-player-tomato--3/
├── src/
│   ├── main.cpp           # Application entry point
│   ├── player.h/cpp       # Audio playback controls
│   ├── playlist.h/cpp     # Playlist management
│   ├── ui.h/cpp          # Terminal UI with ncurses
│   └── audio.h           # Audio utilities (optional)
├── CMakeLists.txt        # Build configuration
├── README.md            # This file
└── .gitignore          # Git ignore file
```

## Features Implemented

✅ Directory scanning for music files
✅ Playlist navigation
✅ Play/Pause/Stop controls
✅ Volume control
✅ Loop and Shuffle modes
✅ ncurses-based terminal UI
✅ Track selection
✅ Status display

## Future Enhancements

- [ ] Real audio decoding (libmpg123, libsndfile)
- [ ] Metadata reading (artist, title, album art)
- [ ] Playlist file support (.m3u, .pls)
- [ ] Equalizer controls
- [ ] Search/filter functionality
- [ ] Configuration file support
- [ ] Keyboard shortcut customization
- [ ] Theme support

## License

MIT License - feel free to use and modify!

## Contributing

Contributions are welcome! Feel free to submit issues and pull requests.

## Author

Created by [wluvstephiie](https://github.com/wluvstephiie)
