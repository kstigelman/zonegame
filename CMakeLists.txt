cmake_minimum_required(VERSION 3.21)
project(ZoneGame LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(ZoneGame src/main.cpp 
    src/Balloon.cpp
    src/Block.cpp
    src/Bomb.cpp
    src/Camera.cpp
    src/Collider.cpp
    src/Controller.cpp
    src/Entity.cpp
    src/Firework.cpp
    src/Game.cpp
    src/GameEffect.cpp
    src/Global.cpp
    src/GUI.cpp
    src/Gun.cpp
    src/Hitbox.cpp
    src/Item.cpp
    src/Level.cpp
    src/LevelMap.cpp
    src/Placeable.cpp
    src/Player.cpp
    src/PlayerGUI.cpp
    src/Projectile.cpp
    src/RepulsionBomb.cpp
    src/Repulsor.cpp
    src/Tile.cpp
    src/TileMap.cpp
    src/Timer.cpp
    src/Trap.cpp
    src/Weapon.cpp
    src/Zone.cpp
    src/ZoneArmor.cpp
)
set(CMAKE_COMPILE_WARNING_AS_ERROR OFF)

target_link_libraries(ZoneGame PRIVATE sfml-graphics)
target_compile_features(ZoneGame PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET ZoneGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:ZoneGame> $<TARGET_FILE_DIR:ZoneGame> COMMAND_EXPAND_LISTS)
endif()

file (COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/index/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release/index)

install(TARGETS ZoneGame)
