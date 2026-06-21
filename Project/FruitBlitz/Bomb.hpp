#ifndef BOMB_HPP
#define BOMB_HPP

#include "SliceableObject.hpp"

class Bomb : public SliceableObject {
public:
    float radius;
    int damage;
    int clicks;

    Bomb(float px, float py, float sx, float sy, float r, int d);
    void draw() const override;
    void explode();
    bool checkCollision(int mouseX, int mouseY) const override;
    void click();
    int getClicks() const;
    void slice() override;
};

#endif // BOMB_HPP
