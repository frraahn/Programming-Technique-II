#include "Bomb.hpp"
#include <graphics.h>
#include <cmath>
#include <iostream>

Bomb::Bomb(float px, float py, float sx, float sy, float r, int d)
    : SliceableObject(px, py, sx, sy), radius(r), damage(d), clicks(0) {}

void Bomb::draw() const {
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x, y, radius, radius);

    // Draw the fuse
    setcolor(RED);
    setlinestyle(SOLID_LINE, 0, 2);
    line(x, y - radius, x, y - radius - 10);
    circle(x, y - radius - 12, 2);
}

void Bomb::explode() {
    std::cout << "Bomb exploded!" << std::endl;
}

bool Bomb::checkCollision(int mouseX, int mouseY) const {
    int distance = sqrt(pow(mouseX - x, 2) + pow(mouseY - y, 2));
    return distance <= radius;
}

void Bomb::click() {
    clicks++;
}

int Bomb::getClicks() const {
    return clicks;
}

void Bomb::slice() {
    explode();
    click();
}
