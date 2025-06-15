#include "flood_fill.h"

FloodFill::FloodFill(Maze *maze, int startX, int startY, int endX, int endY)
{
    _maze = maze;
    _startX = startX;
    _startY = startY;
    _endX = endX;
    _endY = endY;
}

void FloodFill::run()
{
    _maze->setCell(_endX, _endY, 0);

    bool updated = true;
    while (updated)
    {
        updated = false;
        for (int x = 0; x < MAZE_SIZE; x++)
        {
            for (int y = 0; y < MAZE_SIZE; y++)
            {
                if (_maze->getCell(x, y) == -1)
                {
                    continue;
                }

                int currentCellValue = _maze->getCell(x, y);
                int nextCellValue = currentCellValue + 1;

                if (x > 0 && _maze->getCell(x - 1, y) == nextCellValue)
                {
                    _maze->setCell(x, y, nextCellValue);
                    updated = true;
                }
                if (x < MAZE_SIZE - 1 && _maze->getCell(x + 1, y) == nextCellValue)
                {
                    _maze->setCell(x, y, nextCellValue);
                    updated = true;
                }
                if (y > 0 && _maze->getCell(x, y - 1) == nextCellValue)
                {
                    _maze->setCell(x, y, nextCellValue);
                    updated = true;
                }
                if (y < MAZE_SIZE - 1 && _maze->getCell(x, y + 1) == nextCellValue)
                {
                    _maze->setCell(x, y, nextCellValue);
                    updated = true;
                }
            }
        }
    }
}