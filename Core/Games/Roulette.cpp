#include "Games.hpp"

#include "../../Renderer/Renderer.hpp"
#include "../Input.hpp"

void Roulette::Init() {

}

void Roulette::Update(float ts) {
    if (Input::KeyDown(GLFW_KEY_ESCAPE)) {
        this->Close();
        return;
    }


    Renderer::ClearColor({ 0.0f, 1.0f, 0.0f, 1.0f });

    Renderer::BeginScene();
    /* your code goes here */


    /* ------------------- */
    Renderer::EndScene();
}

void Roulette::Terminate() {
    delete this;
}