#pragma once

#include "../GameManager.hpp"

class Poker : public BasicGame {
public:
    Poker() : BasicGame("Poker") { };
    Poker(const Poker&) = default;
    ~Poker() = default;

    void Init() override;
    void Update(float ts) override;
    void Terminate() override;
private:
};