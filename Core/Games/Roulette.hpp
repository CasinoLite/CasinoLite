#pragma once

#include "../GameManager.hpp"

class Roulette : public BasicGame {
public:
    Roulette() : BasicGame("Roulette") { };
    Roulette(const Roulette&) = default;
    ~Roulette() = default;

    void Init() override;
    void Update(float ts) override;
    void Terminate() override;
private:
};