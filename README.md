#  Terminal Music Player .✦ ݁˖

Un reproductor de musica que funciona en la terminal pero quise hacer en C++ porque pense que estría mas padre.

## Features and thinks it can do
╰────── -----· · ୨୧ · ·----- ──────╯

- 🎵 **Solo tiene una rola** - Pero si lo quieres copiar MP3, WAV, FLAC, OGG
- 🎮 **Es interaciva con UI** 
- 📋 **Puedes hacer playlists** - Haz un directorio
- 🔊 **Volumen** 
- ⏱️ **Barrita de progreso** 
- 🎨 **Puedes hacerle shuffle** 
- ⌨️ **Control con tecldito** 

## Cosillas que se ocupan por si me lo copias

- **C++17** or higher
- **CMake 3.10+**
- **ncurses** library
- **GCC** or **Clang** compiler

## yo ocupé esto pero no es afuerza, busca otros metodos después :)

- GCC 15.2.0 — C++ compiler (via MSYS2 MinGW x64)
- CMake 4.3 — Build system
- ncursesw 6.6 — Terminal UI library
- MinGW-w64 — Windows build environment

# En Windows
1. Install MSYS2
2. Open MSYS2 MinGW x64 and run:
```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake mingw-w64-x86_64-make mingw-w64-x86_64-ncurses
```
3. Luego para crear el proyecto:
```bash
mkdir build && cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
```
4. Run!
```bash
./music-player /path/to/your/music/folder
```


### Instala esto dependiendo de lo que ocupes

**Ubuntu/Debian:**
```bash
sudo apt-get install libncurses-dev build-essential cmake
```

**macOS (este es de gays la neta no le muevo):**
```bash
brew install ncurses cmake
```

**Fedora/RHEL:**
```bash
sudo dnf install ncurses-devel cmake gcc-c++
```

## Clonarlo

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

### Controles :)

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

## Estructura // tambien esta el UML por ahí

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

## Cosas que le implementé

✅ Directory scanning for music files
✅ Playlist navigation
✅ Play/Pause/Stop controls
✅ Volume control
✅ Loop and Shuffle modes
✅ ncurses-based terminal UI
✅ Track selection
✅ Status display

## Cosillas que me segun el libro le puedes poner extras 

- [ ] Real audio decoding (libmpg123, libsndfile)
- [ ] Metadata reading (artist, title, album art)
- [ ] Playlist file support (.m3u, .pls)
- [ ] Equalizer controls
- [ ] Search/filter functionality
- [ ] Configuration file support
- [ ] Keyboard shortcut customization
- [ ] Theme support

----

## Contributing
No se que tanto error tenga pero ya corre el problema es que para que reproduzca algo todavía no jala

## Quien chuchas pasó 10 noches haciendo esta madre??
yo : [wluvstephiie](https://github.com/wluvstephiie)
