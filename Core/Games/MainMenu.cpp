#include "Games.hpp"

#include "../../Renderer/Renderer.hpp"
#include "../Input.hpp"

std::shared_ptr<Texture> textures[2];

void MainMenu::Init() {
    textures[0] = Texture::Create("../Assets/Textures/test.png");
    textures[1] = Texture::Create("../Assets/Textures/test2.png");
}

void MainMenu::Update(float ts) {
    if (Input::KeyDown(GLFW_KEY_1)) {
        state_.nextGame = Game::SLOTS;
        this->Close();
        return;
    }
    if (Input::KeyDown(GLFW_KEY_2)) {
        state_.nextGame = Game::ROULETTE;
        this->Close();
        return;
    }
    if (Input::KeyDown(GLFW_KEY_3)) {
        state_.nextGame = Game::GO_FISH;
        this->Close();
        return;
    }
    if (Input::KeyDown(GLFW_KEY_4)) {
        state_.nextGame = Game::BLACKJACK;
        this->Close();
        return;
    }
    if (Input::KeyDown(GLFW_KEY_5)) {
        state_.nextGame = Game::POKER;
        this->Close();
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
    Renderer::DrawTexturedQuad({ -0.5f, 0.0f }, { 1.0f, 1.0f }, textures[0]);
    Renderer::DrawRotatedTexturedQuad({ 0.0f, 0.0f }, { 0.5f, 0.5f }, r * 180.0f, textures[1]);

    Renderer::EndScene();

    /* ----------------------------- */
}

void MainMenu::Terminate() {


    delete this;
}
