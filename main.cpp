#include "pch.h"
#include <vector>
#include <iostream>

using namespace std;

void printTower(vector<vector<char>>& tower)
{
    for (const auto &row : tower)
    {
        for (const auto &s : row)
        {
            std::cout << s;
        }
        std::cout << '\n';
    }
}

void buildTower(vector<vector<char>>& tower, int floors, int blockWidth, int blockHeight)
{
    std::cout << "Building tower with " << floors << " floors and block of dimensions (" << blockWidth << ", " << blockHeight << ")";
    std::cout << '\n' << '\n';

    int towerWidth = blockWidth + (floors - 1) * (blockWidth * 2);
    int towerHeight = floors * blockHeight;

    // populate vector
    for (int currFloor = 1; currFloor <= floors; ++currFloor)
    {
        for (int blockRow = 0; blockRow < blockHeight; ++blockRow)
        {
            // calculate how many stars
            int numberOfStars = blockWidth + ((blockWidth * 2) * (currFloor - 1));

            // calculate how much space on each side
            int spacesOnOneSide = (towerWidth - numberOfStars) / 2;

            // create floor
            vector<char> slice;
            slice.insert(slice.begin(), spacesOnOneSide, ' ');
            slice.insert(slice.end(), numberOfStars, '*');
            slice.insert(slice.end(), spacesOnOneSide, ' ');

            // popluate tower
            tower.insert(tower.end(), slice);
        }
    }
}

int main()
{
    vector<vector<char>> tower;
    buildTower(tower, 6, 2, 1);
    printTower(tower);
}