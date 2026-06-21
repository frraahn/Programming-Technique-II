#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <string>
#include "SliceableObject.hpp"
#include "Score.hpp"

class Fruit : public SliceableObject {
public:
    Fruit(float px, float py, float sx, float sy, const std::string& t, int p);

    void draw() const override;
    void givePoints(Score& score);
    bool checkCollision(int mouseX, int mouseY) const override;
    void slice() override;

private:
    std::string type;
    int points;
};

#endif // FRUIT_HPP
