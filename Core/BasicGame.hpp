#include <string>

enum class Game {
    EXIT = 0,
    MAIN_MENU,
    SLOTS,
    ROULETTE,
    GOFISH,
    BLACKJACK,
    POKER
};

// holds the state of the game until terminated
struct GameState {
    Game nextGame = Game::MAIN_MENU;
    bool shouldClose = false;
};

class BasicGame {
public:
    explicit BasicGame(std::string title = "Game")
            :title_(std::move(title)) {

    }
    BasicGame(const BasicGame&) = default;
    ~BasicGame() = default;

    // implemented per game
    virtual void Init() = 0;
    virtual void Update(float ts) = 0;
    virtual void Terminate() = 0;

    // general for every game
    inline GameState GetGameState() const { return state_; }
protected:
    inline void Close() { state_.shouldClose = true; }
protected:
    std::string title_;
    GameState state_;
};