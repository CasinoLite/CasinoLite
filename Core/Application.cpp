#include "Application.hpp"

#include <iostream>
#include <chrono>

double GetTime() {
    using std::chrono::duration_cast;
    using std::chrono::microseconds;
    using std::chrono::system_clock;
    auto micros_since_epoch = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    return static_cast<double>(micros_since_epoch) / 1000.0;
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
    float ts = 0;
    double start = GetTime(), end = 0;

    while (!window_.ShouldClose()) {
        window_.Update();

        end = GetTime();
        ts = static_cast<float>(end - start);
        start = end;

        GameManager::Update();
        auto game = GameManager::ActiveGame();
        game->Update(ts);
    }

    GameManager::Terminate();
}

