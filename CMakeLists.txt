cmake_minimum_required(VERSION 3.25)
project(CasinoLite)

set(CMAKE_CXX_STANDARD 17)

set(CORE_SOURCES
    "Core/Application.cpp"
    "Core/Window.cpp"
    "Core/Input.cpp"
    "Core/GameManager.cpp"
)

set(GAME_SOURCES
    "Core/Games/MainMenu.cpp"
    "Core/Games/Slots.cpp"
    "Core/Games/Roulette.cpp"
    "Core/Games/GoFish.cpp"
        "Core/Games/Poker.cpp")

set(RENDERER_SOURCES
    "Renderer/Shader.cpp"
    "Renderer/Texture.cpp"
    "Renderer/Camera.cpp"
    "Renderer/Primitive.cpp"
    "Renderer/Renderer.cpp"
    "Renderer/VertexArray.cpp"
    "Renderer/Buffers.cpp")

set(OTHER_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/src/glad.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb/stb.cpp"
        Core/Window.hpp
        Core/GameManager.cpp GUI/GUI.cpp GUI/GUI.hpp Core/Games/Games.hpp Core/Games/Blackjack.cpp)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw")
add_executable(CasinoLite main.cpp ${CORE_SOURCES} ${GAME_SOURCES} ${RENDERER_SOURCES} ${OTHER_SOURCES} )

target_include_directories(${PROJECT_NAME}
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb")

target_link_libraries(${PROJECT_NAME}
        PRIVATE glfw)