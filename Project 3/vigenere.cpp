/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Yancheng Xiang
 * ericxyc
 *
 * EECS 183: Project 3
 * Fall 2025
 *
 * EECS 183 Project 3 cipher vigenere
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string vigenereCipher(string original, string keyword, bool encrypt) {
    // TODO: implement
    int shift;
    int k = 0;
    for (int i = 0; i < original.size(); ++i) {
        //make change ang update k only when the char read is a alpha
        if (isalpha(original.at(i))) {
            shift = keyword.at(k) - 'A';
            if (!encrypt) {
                shift = - shift;
            }
            original.at(i) = shiftAlphaCharacter(original.at(i), shift);
            k = (k + 1) % keyword.size();
        }
    }
    return original;
}
