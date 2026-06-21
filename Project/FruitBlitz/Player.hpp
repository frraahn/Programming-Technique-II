#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Score.hpp"
#include "SliceableObject.hpp"
#include "Fruit.hpp"
#include "Bomb.hpp"

class Player {
public:
    std::string name;
    int lives;
    Score score;

    Player(const std::string& n);
    void sliceObject(SliceableObject* obj);
    void loseLife();
    bool isAlive() const;
};

#endif // PLAYER_HPP
