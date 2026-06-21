#include "Fruit.hpp"
#include <graphics.h>
#include <cmath>
#include <cstdlib>  // Include for rand() and srand()
#include <ctime>    // Include for time()

Fruit::Fruit(float px, float py, float sx, float sy, const std::string& t, int p)
    : SliceableObject(px, py, sx, sy), type(t), points(p) {}

void Fruit::draw() const {
    if (type == "Apple") {
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        fillellipse(static_cast<int>(x), static_cast<int>(y), 15, 15);

        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        fillellipse(static_cast<int>(x) - 5, static_cast<int>(y) - 12, 6, 2);

        setcolor(BROWN);
        setfillstyle(SOLID_FILL, BROWN);
        bar(static_cast<int>(x) - 1, static_cast<int>(y) - 18, static_cast<int>(x) + 5, static_cast<int>(y) - 9);
    } else if (type == "Orange") {
        setcolor(COLOR(255, 165, 0)); // ORANGE color
        setfillstyle(SOLID_FILL, COLOR(255, 165, 0));
        fillellipse(static_cast<int>(x), static_cast<int>(y), 15, 15);

        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        fillellipse(static_cast<int>(x) - 5, static_cast<int>(y) - 12, 5, 3);
        fillellipse(static_cast<int>(x) + 5, static_cast<int>(y) - 12, 5, 3);
    } else if (type == "Watermelon") {
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        int poly[6] = {static_cast<int>(x), static_cast<int>(y), static_cast<int>(x) - 25, static_cast<int>(y) + 50, static_cast<int>(x) + 25, static_cast<int>(y) + 50};
        fillpoly(3, poly);

        setcolor(GREEN);
        setlinestyle(SOLID_LINE, 0, 5);
        line(static_cast<int>(x) - 25, static_cast<int>(y) + 50, static_cast<int>(x) + 25, static_cast<int>(y) + 50);

        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        int seedPositions[6][2] = {
            {static_cast<int>(x), static_cast<int>(y) + 10}, {static_cast<int>(x) - 5, static_cast<int>(y) + 15},
            {static_cast<int>(x) + 5, static_cast<int>(y) + 15}, {static_cast<int>(x) - 10, static_cast<int>(y) + 20},
            {static_cast<int>(x) + 10, static_cast<int>(y) + 20}, {static_cast<int>(x), static_cast<int>(y) + 25}
        };
        for (int i = 0; i < 6; ++i) {
            fillellipse(seedPositions[i][0], seedPositions[i][1], 1, 1);
        }
    } else if (type == "Cherry") {
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        fillellipse(static_cast<int>(x), static_cast<int>(y) + 10, 10, 10);
        fillellipse(static_cast<int>(x) + 20, static_cast<int>(y) + 10, 10, 10);

        setcolor(BROWN);
        setlinestyle(SOLID_LINE, 0, 3);
        int stemLength = 17;
        arc(static_cast<int>(x), static_cast<int>(y), 0, 60, stemLength);
        arc(static_cast<int>(x) + 20, static_cast<int>(y), 120, 180, stemLength);

        int stemConnectionX = static_cast<int>(x) + 10;
        int stemConnectionY = static_cast<int>(y);
        line(static_cast<int>(x) + static_cast<int>(stemLength * cos(60 * M_PI / 180)), static_cast<int>(y) - static_cast<int>(stemLength * sin(60 * M_PI / 180)), stemConnectionX, stemConnectionY);
        line(static_cast<int>(x) + 20 + static_cast<int>(stemLength * cos(120 * M_PI / 180)), static_cast<int>(y) - static_cast<int>(stemLength * sin(120 * M_PI / 180)), stemConnectionX, stemConnectionY);

        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        fillellipse(stemConnectionX - 10, stemConnectionY - 20, 10, 5);
        fillellipse(stemConnectionX + 10, stemConnectionY - 20, 10, 5);
    }
}

void Fruit::givePoints(Score& score) {
    score.addPoints(points);
}

bool Fruit::checkCollision(int mouseX, int mouseY) const {
    int distance = static_cast<int>(sqrt(pow(mouseX - x, 2) + pow(mouseY - y, 2)));
    return distance <= 20;
}

void Fruit::slice() {
    // Slicing a fruit simply involves giving points
    // The actual object removal logic can be handled elsewhere
}
