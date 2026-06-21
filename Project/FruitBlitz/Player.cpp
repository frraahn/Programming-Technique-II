#include "Player.hpp"

Player::Player(const std::string& n) : name(n), lives(3), score() {}

void Player::sliceObject(SliceableObject* obj) {
    obj->slice();
    if (Fruit* fruit = dynamic_cast<Fruit*>(obj)) {
        fruit->givePoints(score);
    } else if (Bomb* bomb = dynamic_cast<Bomb*>(obj)) {
        bomb->explode();
        loseLife();
    }
}

void Player::loseLife() {
    lives--;
}

bool Player::isAlive() const {
    return lives > 0;
}
