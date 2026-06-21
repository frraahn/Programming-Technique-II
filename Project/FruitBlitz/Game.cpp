#include "Game.hpp"
#include <graphics.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game() : currentScore(0), isGameOver(false), player(new Player("Player")), lastSpawnTime(clock()) {}

Game::~Game() {
    delete player;
    for (auto obj : objects) {
        delete obj;
    }
}

void Game::startGame() {
    player->score.resetScore();
    isGameOver = false;
    generateObjects();
}

void Game::endGame() {
    isGameOver = true;
    std::cout << "Game Over!" << std::endl;
}

void Game::displayScore() const {
    char buffer[50];
    sprintf(buffer, "Score: %d", player->score.points);
    outtextxy(10, 10, buffer);

    sprintf(buffer, "Lives: %d", player->lives);
    outtextxy(10, 30, buffer);
}

void Game::generateObjects() {
    objects.clear();
    int numFruits = rand() % 10 + 5; // Random number of fruits between 5 and 14
    for (int i = 0; i < numFruits; ++i) {
        float x = rand() % getmaxx();
        float y = rand() % getmaxy();
        float sx = static_cast<float>(rand() % 3 + 1) / 5.0f;
        float sy = static_cast<float>(rand() % 3 + 1) / 5.0f;
        int points = 3;
        std::string type;
        switch (rand() % 4) {
            case 0:
                type = "Apple";
                break;
            case 1:
                type = "Orange";
                break;
            case 2:
                type = "Watermelon";
                break;
            case 3:
                type = "Cherry";
                points = 5;
                break;
        }
        objects.push_back(new Fruit(x, y, sx, sy, type, points));
    }

    // Add three bombs
    for (int i = 0; i < 3; ++i) {
        float bombX = rand() % getmaxx();
        float bombY = rand() % getmaxy();
        float bombSx = static_cast<float>(rand() % 3 + 1) / 5.0f;
        float bombSy = static_cast<float>(rand() % 3 + 1) / 5.0f;
        objects.push_back(new Bomb(bombX, bombY, bombSx, bombSy, 15, 10));
    }
}

void Game::update(float timeDelta) {
    for (auto obj : objects) {
        obj->x += obj->sx * timeDelta;
        obj->y += obj->sy * timeDelta;

        if (obj->x < 0 || obj->x > getmaxx() || obj->y < 0 || obj->y > getmaxy()) {
            obj->x = rand() % getmaxx();
            obj->y = rand() % getmaxy();
        }
    }

    if ((clock() - lastSpawnTime) / CLOCKS_PER_SEC >= 2) {
        generateObjects();
        lastSpawnTime = clock();
    }

    currentScore = player->score.points;
}

void Game::draw() const {
    for (const auto& obj : objects) {
        obj->draw();
    }
    displayScore();
}

void Game::handleMouseClick(int mouseX, int mouseY) {
    for (auto it = objects.begin(); it != objects.end();) {
        if ((*it)->checkCollision(mouseX, mouseY)) {
            player->sliceObject(*it);
            delete *it;
            it = objects.erase(it);
        } else {
            ++it;
        }
    }
}
