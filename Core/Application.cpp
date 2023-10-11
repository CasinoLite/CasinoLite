#include "Application.hpp"

#include <iostream>
#include <chrono>

double GetTime() {
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;
    using std::chrono::system_clock;
    auto millis_since_epoch = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    return static_cast<double>(millis_since_epoch);
}

Application* Application::pInstance_s = nullptr;

Application::Application() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "gladLoadGLLoader error: could not load OpenGL" << std::endl;
        std::exit(-1);
    }
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Generates vertex buffers and shaders needed to draw primitives
    Renderer::Init();

    // Initializes each game
    GameManager::Init();
}

void Application::Run() {
    double ts = 0, end = 0;
    auto start = GetTime();

    while (!window_.ShouldClose()) {
        window_.Update();

        end = GetTime();
        ts = end - start;
        start = end;

        GameManager::Update();
        auto game = GameManager::ActiveGame();
        game->Update(0);
    }

    GameManager::Terminate();
}

