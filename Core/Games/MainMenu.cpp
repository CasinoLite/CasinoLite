#include "../Application.hpp"
#include "../../Renderer/Renderer.hpp"

#include <iostream>

void MainMenu::Init() {

}

void MainMenu::Update() {
    if (Input::KeyDown(GLFW_KEY_1)) {
        std::cout << "playing slots\n";
        Application::SetActiveGame(Games::pSlots_g);
        return;
    }
    if (Input::KeyDown(GLFW_KEY_2)) {
        std::cout << "playing roulette\n";
        Application::SetActiveGame(Games::pRoulette_g);
        return;
    }
    if (Input::KeyDown(GLFW_KEY_3)) {
        std::cout << "playing go fish\n";
        Application::SetActiveGame(Games::pGoFish_g);
        return;
    }
    if (Input::KeyDown(GLFW_KEY_4)) {
        std::cout << "playing blackjack\n";
        Application::SetActiveGame(Games::pBlackjack_g);
        return;
    }
    if (Input::KeyDown(GLFW_KEY_5)) {
        std::cout << "playing poker\n";
        Application::SetActiveGame(Games::pPoker_g);
        return;
    }


    /* ------- Renderer DEMO ------- */

    // Clear the screen with a given color
    Renderer::ClearColor({ 1.0, 0.0f, 1.0f, 1.0f });

    // Before making any "Draw" calls, begin the scene...
    Renderer::BeginScene();

    // Primitive Draw Calls
    auto r = static_cast<float>(glm::sin(glfwGetTime()));
    Renderer::DrawRotatedQuad({ r, 0.0f }, { 1.0f, 1.0f }, r * 180.0f, { 1.0f, 0.0f, 0.0f, 1.0f });
    Renderer::DrawQuad({ 0.0f, 0.0f }, { 1.0f, 1.0f }, {1.0f, 1.0f, 1.0f, 1.0f});

//    auto texture = Texture::Create("../Assets/Textures/test.png");
//    Renderer::DrawTexturedQuad({ 0.0f, 0.0f }, { 0.5f, 0.5f }, texture);

    Renderer::EndScene();
}

void MainMenu::Terminate() {

}