#pragma once

#include "../GameManager.hpp"

class Blackjack : public BasicGame {
public:
    Blackjack() : BasicGame("Blackjack") { };
    Blackjack(const Blackjack&) = default;
    ~Blackjack() = default;

    void Init() override;
    void Update(float ts) override;
    void Terminate() override;
private:
};