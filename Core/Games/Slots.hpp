#pragma once

#include "../BasicGame.hpp"

class Slots : public BasicGame {
public:
    Slots() : BasicGame("Slots") { };
    Slots(const Slots&) = default;
    ~Slots() = default;

    void Init() override;
    void Update(float ts) override;
    void Terminate() override;
private:
};