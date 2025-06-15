#include "maze.h"

Maze::Maze()
{
    for (uint8_t i = 0; i < MAZE_SIZE; i++)
    {
        for (uint8_t j = 0; j < MAZE_SIZE; j++)
        {
            _maze[i][j] = -1;
        }
    }
}

void Maze::setCell(uint8_t x, uint8_t y, uint8_t value)
{
    if (x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE)
    {
        _maze[x][y] = value;
    }
}

uint8_t Maze::getCell(uint8_t x, uint8_t y)
{
    if (x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE)
    {
        return _maze[x][y];
    }
    return -1;
}

void Maze::printMaze()
{
    for (uint8_t i = 0; i < MAZE_SIZE; i++)
    {
        for (uint8_t j = 0; j < MAZE_SIZE; j++)
        {
            Serial.print(_maze[i][j]);
            Serial.print(" ");
        }
        Serial.println();
    }
}

void Maze::setStart(uint8_t x, uint8_t y)
{
    _start[0] = x;
    _start[1] = y;
}

void Maze::setEnd(uint8_t x, uint8_t y)
{
    _end[0] = x;
    _end[1] = y;
}
