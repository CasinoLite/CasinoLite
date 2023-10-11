#pragma once

#include "../GameManager.hpp"

class GoFish : public BasicGame {
public:
    GoFish() : BasicGame("Go Fish") { };
    GoFish(const GoFish&) = default;
    ~GoFish() = default;

    void Init() override;
    void Update(float ts) override;
    void Terminate() override;
private:
};