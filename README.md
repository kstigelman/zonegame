# Welcome to Zone Game
Survive the Zone and be the last one standing in this 4 player multiplayer game prototype.
Use items and build walls to escape and trap your friends.

## Controls
Player 1 (Blue):
    W - Jump
    A/D - Move Left/Right
    S - Swap Item
    E - Use Item
Player 2 (Red):
    I - Jump
    J/L - Move Left/Right
    K - Swap Item
    O - Use Item
Player 3 (Green):
    Up Arrow - Jump
    Left/Right Arrow - Move Left/Right
    Down Arrow - Swap Item
    Right Ctrl - Use Item
Player 4 (Yellow):
    NUMPAD 8 - Jump
    NUMPAD 4/NUMPAD 6 - Move Left/Right
    NUMPAD 6 - Swap Item
    NUMPAD 9 - Use Item

## How to Use
1. Clone repository to local machine
2. Open terminal/command prompt and cd into working directory
3. Run the following CMake commands
    For a single-configuration generator (typically the case on Linux and macOS):
    ```
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
    cmake --build build
    ```

    For a multi-configuration generator (typically the case on Windows):
    ```
    cmake -S . -B build
    cmake --build build --config Release
    ```
