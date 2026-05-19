# Notas del Proyecto: Music Player Tomato

## ¿Qué es este proyecto?
Es un reproductor de música en terminal escrito en C++ que hice cuando tenía como 15 años. Lo retomé para hacerlo correr en Windows y arreglarle varios bugs que tenía.

---

## Herramientas que tuve que instalar y por qué

### MinGW (Compilador de C++)
Lo instalé porque sin un compilador la computadora no puede entender mi código. El compilador traduce el C++ a instrucciones que la máquina entiende. Lo descargué de winlibs.com y tuve que agregarlo manualmente al PATH de Windows para que la terminal lo encontrara.

**PATH**: es una variable del sistema que le dice a Windows en qué carpetas buscar programas cuando los llamas desde la terminal. Sin esto, aunque MinGW estuviera instalado, la terminal no lo encontraba.

### CMake
Lo instalé porque el proyecto usa un archivo `CMakeLists.txt` que describe cómo compilarse. CMake lee ese archivo y genera las instrucciones exactas para el compilador. Es como el director de obra del proyecto.

### MSYS2
Lo instalé porque el proyecto fue hecho pensando en Linux y MSYS2 simula un entorno Linux dentro de Windows. Además tiene `pacman`, que es su gestor de paquetes (una especie de tienda de librerías). De aquí en adelante todo lo hice desde la terminal **MSYS2 MinGW x64**.

### ncurses
Es la librería que dibuja la interfaz en la terminal, las cajitas, el playlist, la barra de progreso. Sin ella el proyecto ni compilaba. La instalé con:
```bash
pacman -S mingw-w64-x86_64-ncurses
```
Un problema que tuve es que en Windows se llama `ncursesw` (con w al final) y el `CMakeLists.txt` buscaba `ncurses`. Tuve que editar el archivo para cambiarlo.

### ffmpeg / ffplay
Es la herramienta que realmente reproduce el audio. Mi proyecto no tiene motor de audio propio, delega esa tarea a ffplay. Lo instalé con:
```bash
pacman -S mingw-w64-x86_64-ffmpeg
```

---

## Cómo compilé el proyecto

Una vez instalado todo, el proceso de compilación fue:
```bash
cd ~/music-player-tomato--3
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
```

**¿Qué hace cada comando?**
- `mkdir build` — crea una carpeta donde van a vivir los archivos compilados
- `cmake ..` — lee el CMakeLists.txt y prepara todo para compilar
- `mingw32-make` — compila el código y genera el ejecutable

Para correr el player:
```bash
./music-player /ruta/a/mi/musica
```

---

## Bugs que arreglé

### 1. Pantalla parpadeante — `ui.cpp`

**¿Qué pasaba?**
La pantalla se crasheaba y parpadeaba constantemente.

**¿Por qué pasaba?**
En la función `displayMenu()` había dos líneas que borraban y redibujaban toda la pantalla en cada ciclo del loop:
```cpp
clear();
refresh();
```
Esto hacía que la pantalla entera se borrara miles de veces por segundo, causando el parpadeo.

**¿Qué hice?**
Borré esas dos líneas. Cada ventana ya tiene su propio `werase()` y `wrefresh()` que la redibuja sola sin afectar las demás.

---

### 2. Canciones empalmadas — `player.cpp`

**¿Qué pasaba?**
Al cambiar de canción, la anterior seguía sonando encima de la nueva.

**¿Por qué pasaba?**
El código original usaba `system()` para lanzar ffplay. Este comando en Windows lanza el proceso pero no te da ningún control sobre él, es como contratar a alguien y perder su número de teléfono. Nunca mataba el ffplay anterior antes de lanzar uno nuevo.

**¿Qué hice?**
Reemplacé `system()` por `CreateProcess()`, que es una función de la API de Windows que al lanzar un proceso te devuelve un **HANDLE** (un control remoto del proceso). Guardé ese handle en una variable llamada `ffplayProcess` en la clase `Player`.

Luego creé la función `killFfplay()` que:
1. Revisa si `ffplayProcess` no es `nullptr` (es decir, si hay un proceso corriendo)
2. Lo mata con `TerminateProcess()`
3. Libera el handle con `CloseHandle()`
4. Pone `ffplayProcess` en `nullptr` de nuevo

Ahora cada vez que llamo `play()`, primero llamo `killFfplay()` para matar el anterior.

---

### 3. Player no se cerraba bien — `player.cpp`

**¿Qué pasaba?**
Al presionar Q para salir, el player se cerraba pero ffplay seguía sonando en segundo plano.

**¿Por qué pasaba?**
El código solo ponía `running = false` para salir del loop, pero nunca mataba el proceso de ffplay.

**¿Qué hice?**
Al agregar `killFfplay()` en el destructor `~Player()`, cuando el objeto Player se destruye al salir del programa, automáticamente mata ffplay también.

---

### 4. Letras raras en la interfaz — `ui.cpp`

**¿Qué pasaba?**
En la playlist y la barra de progreso aparecían caracteres extraños como `M-b~T~@`.

**¿Por qué pasaba?**
El código usaba caracteres Unicode como `█`, `►`, `─` que la terminal de Windows no sabe renderizar bien.

**¿Qué hice?**
Los reemplacé por caracteres ASCII simples que cualquier terminal entiende: `=`, `-`, `>`.

---

## Mejoras estéticas que agregué

Le agregué colores góticos usando la librería ncurses:
- Bordes y títulos en **rojo**
- Canciones normales en **blanco**
- Canción seleccionada en **rojo con negrita**
- Status en **magenta**
- Fondo negro

Para activar colores en ncurses hay que:
1. Llamar `start_color()` en la inicialización
2. Definir pares de color con `init_pair(id, color_texto, color_fondo)`
3. Activarlos con `wattron(ventana, COLOR_PAIR(id))` antes de dibujar
4. Desactivarlos con `wattroff()` después

---

## Pendiente

- **Pausa real** — Actualmente pause() solo cambia una variable interna pero no suspende ffplay. La solución es matar ffplay, recordar en qué segundo iba, y al reanudar relanzarlo desde ese segundo con el flag `-ss`.
- **Control de volumen real** — Mismo problema, el volumen solo cambia internamente pero ffplay no se entera.
