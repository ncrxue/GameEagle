#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

#include "LightsOut.h"

using namespace std;

void printGrid(const vector<vector<bool>> &grid);
void pressSquare(vector<vector<bool>> &grid, unsigned row, unsigned col);
void isWin(const vector<vector<bool>> &grid, bool &win);

void LightsOut() {
    
    printf("\n");
    int sideLength = 0;
    while (sideLength < 4 || sideLength > 10) {
        printf("Enter side length of lights square (min 4, max 10): ");
        cin >> sideLength;
        if (sideLength >= 4 && sideLength <= 10) {
            break;
        }
        printf("Invalid size.\n");
    }

    // Note: access this 2D Vector in row-major order
    vector<vector<bool>> light2DVector(sideLength, vector<bool>(sideLength, false));

    // Randomly set grid for every game
    time_t current_time = time(0);
    srand(current_time);
    for (int i = 0; i < sideLength; i++) {
        for (int j = 0; j < sideLength; j++) {
            if (rand() % 2 == 0) { // Ensures that each grid possible to solve
                pressSquare(light2DVector, i, j); 
            }
        }
    }

    bool win = false;

    printGrid(light2DVector);

    unsigned rowToClick = 1;
    unsigned colToClick = 1;
    while (win == false) {
        printf("\033[2J");
        printf("GOAL: Turn off all the lights!\n");
        printf("\n");
        printGrid(light2DVector);
        printf("\n");
        printf("Which square should I press?\n");
        printf("Row: ");
        cin >> rowToClick;
        printf("Column: ");
        cin >> colToClick;
        pressSquare(light2DVector, rowToClick - 1, colToClick - 1);
        isWin(light2DVector, win);
    }
    printf("\033[2J");
    printGrid(light2DVector);
    printf("YOU WIN!\n\n");
    
    // // Test seeded random w/ time
    // time_t current_time = time(0);
    // srand(current_time);
    // printf("The local date and time is: %i\n", current_time);
    // printf("Random number: %i\n", rand() % 2);
}

void printGrid(const vector<vector<bool>> &grid) {
    for (unsigned i = 0; i < grid.size(); i++) {
            for (unsigned j = 0; j < grid.size(); j++) {
                if (grid.at(i).at(j) == true) {
                    printf("\x1B[97m%c%c\033[0m  ", 178, 178);
                }
                else {
                    printf("\x1B[90m%c%c\033[0m  ", 178, 178);
                }
            }
            printf("\n\n");
        }
}

void pressSquare(vector<vector<bool>> &grid, unsigned row, unsigned col) {
    // flip square that is pressed
    grid.at(row).at(col) = !grid.at(row).at(col);
    
    // flip square left of pressed square, if exists
    if (col >= 1) {
        grid.at(row).at(col - 1) = !grid.at(row).at(col - 1);
    }

    // flip square right of pressed square, if exists
    if (col + 1 <= grid.size() - 1) {
        grid.at(row).at(col + 1) = !grid.at(row).at(col + 1);
    }

    // flip square above pressed square, if exists
    if (row >= 1) {
        grid.at(row - 1).at(col) = !grid.at(row - 1).at(col);
    }

    // flip square below pressed square, if exists
    if (row + 1 <= grid.size() - 1) {
        grid.at(row + 1).at(col) = !grid.at(row + 1).at(col);
    }
}

void isWin(const vector<vector<bool>> &grid, bool &win) {
    for (unsigned i = 0; i < grid.size(); i++) {
        for (unsigned j = 0; j < grid.size(); j++) {
            if (grid.at(i).at(j) == true) {
                return;
            }
        }
    }
    win = true;
}

