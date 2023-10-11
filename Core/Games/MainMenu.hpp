#pragma once

#include "../BasicGame.hpp"

class MainMenu : public BasicGame {
public:
    MainMenu() : BasicGame("Main Menu") { };
    MainMenu(const MainMenu&) = default;
    ~MainMenu() = default;

    void Init() override;
    void Update(float ts) override;
    void Terminate() override;
private:
};