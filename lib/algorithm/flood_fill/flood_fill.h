#ifndef FLOODFILL_H
#define FLOODFILL_H

#include <Arduino.h>
#include "maze/maze.h"

class FloodFill
{
private:
    Maze *_maze;
    int _startX;
    int _startY;
    int _endX;
    int _endY;

public:
    FloodFill(Maze *maze, int startX, int startY, int endX, int endY);
    void run();
    int getNextMove(int x, int y);
};

#endif // FLOODFILL_H
