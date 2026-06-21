#include "Score.hpp"

Score::Score() : points(0) {}

void Score::addPoints(int p) {
    points += p;
}

void Score::resetScore() {
    points = 0;
}
