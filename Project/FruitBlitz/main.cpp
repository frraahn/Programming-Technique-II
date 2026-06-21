#include <graphics.h>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"

void drawGrid() {
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH); // Set thicker line style
    int screenWidth = getmaxx();
    int screenHeight = getmaxy();
    int cmToPixels = 37; // Approximate conversion from cm to pixels for common screen DPI

    for (int x = cmToPixels * 2; x < screenWidth; x += cmToPixels * 2) {
        line(x, 0, x, screenHeight);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int lightPink = RGB(255, 182, 193); // Define light pink color using RGB
    setbkcolor(lightPink);
    cleardevice();

    srand(time(0));
    Game game;
    game.startGame();

    // Draw the grid lines once
    drawGrid();

    float timeDelta = 0.1f;
    while (!game.isGameOver && game.player->isAlive()) {
        // Only clear the game elements, not the grid
        setviewport(0, 0, getmaxx(), getmaxy(), 1);
        clearviewport();
        
        // Reset the background color and redraw the grid lines
        setbkcolor(lightPink);
        drawGrid();

        // Update and draw the game elements
        game.update(timeDelta);
        game.draw();

        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mouseX = mousex();
            int mouseY = mousey();
            game.handleMouseClick(mouseX, mouseY);
            clearmouseclick(WM_LBUTTONDOWN);
        }

        delay(50);
    }

    game.endGame();
    delay(3000); // Delay to view the result
    closegraph();
    return 0;
}
