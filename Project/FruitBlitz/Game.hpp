#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <ctime>
#include "Player.hpp"
#include "SliceableObject.hpp"
#include "Fruit.hpp"
#include "Bomb.hpp"

class Game {
public:
    int currentScore;
    bool isGameOver;
    Player* player;
    std::vector<SliceableObject*> objects;
    clock_t lastSpawnTime;

    Game();

    void startGame();
    void endGame();
    void displayScore() const;
    void generateObjects();
    void update(float timeDelta);
    void draw() const;
    void handleMouseClick(int mouseX, int mouseY);
    ~Game();
};

#endif // GAME_HPP
