#pragma once

#include "Input.hpp"

#include <utility>
#include <string>

class Game {
public:
    explicit Game(std::string title = "Game")
        :title_(std::move(title)) {

    }
    Game(const Game&) = default;
    ~Game() = default;

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Terminate() = 0;
private:
    std::string title_;
};

class MainMenu : public Game {
public:
    MainMenu() : Game("Main Menu") { };
    MainMenu(const MainMenu&) = default;
    ~MainMenu() = default;

    void Init() override;
    void Update() override;
    void Terminate() override;
private:
};

class Slots : public Game {
public:
    Slots() : Game("Slots") { };
    Slots(const Slots&) = default;
    ~Slots() = default;

    void Init() override;
    void Update() override;
    void Terminate() override;
private:
};

class Roulette : public Game {
public:
    Roulette() : Game("Roulette") { };
    Roulette(const Roulette&) = default;
    ~Roulette() = default;

    void Init() override;
    void Update() override;
    void Terminate() override;
private:
};

class GoFish : public Game {
public:
    GoFish() : Game("Go Fish") { };
    GoFish(const GoFish&) = default;
    ~GoFish() = default;

    void Init() override;
    void Update() override;
    void Terminate() override;
private:
};

class Blackjack : public Game {
public:
    Blackjack() : Game("Blackjack") { };
    Blackjack(const Blackjack&) = default;
    ~Blackjack() = default;

    void Init() override;
    void Update() override;
    void Terminate() override;
private:
};

class Poker : public Game {
public:
    Poker() : Game("Poker") { };
    Poker(const Poker&) = default;
    ~Poker() = default;

    void Init() override;
    void Update() override;
    void Terminate() override;
private:
};

namespace Games {
    inline MainMenu* pMainMenu_g = new MainMenu();
    inline Slots* pSlots_g = new Slots();
    inline Roulette* pRoulette_g = new Roulette();
    inline GoFish* pGoFish_g = new GoFish();
    inline Blackjack* pBlackjack_g = new Blackjack();
    inline Poker* pPoker_g = new Poker();
}