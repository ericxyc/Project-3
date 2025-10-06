/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Yancheng Xiang
 * ericxyc
 *
 * EECS 183: Project 3
 * Fall 2025
 *
 * EECS 183 Project 3 cipher utility
 */

#include "utility.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string toUpperCase(string original) {
    // TODO: implement

    // NOTE: return "" to avoid compile error
    //       remove it after implementing
    return "";
}

string removeNonAlphas(string original) {
    // TODO: implement

    // NOTE: return "" to avoid compile error
    //       remove it after implementing
    return "";
}

int charToInt(char original) {
    // TODO: implement

    // NOTE: return 0 to avoid compile error
    //       remove it after implementing
    return 0;
}

string removeDuplicate(string original) {
    // TODO: implement

    // NOTE: return "" to avoid compile error
    //       remove it after implementing
    return "";
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid [SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
