#ifndef MAZE_H
#define MAZE_H

#include <Arduino.h>

#define MAZE_SIZE 16

class Maze
{
private:
    uint8_t _maze[MAZE_SIZE][MAZE_SIZE];
    uint8_t _start[2];
    uint8_t _end[2];

public:
    Maze();
    void setCell(uint8_t x, uint8_t y, uint8_t value);
    uint8_t getCell(uint8_t x, uint8_t y);
    void printMaze();
    void setStart(uint8_t x, uint8_t y);
    void setEnd(uint8_t x, uint8_t y);
};

#endif // MAZE_H
