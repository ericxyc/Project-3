//
//  test.cpp
//  Project 3
//
//  Created by 项彦澄 on 2025/10/4
//
//name1: Yancheng Xiang
//uniquename1: ericxyc
//name2: Yibei Zhai
//uniquename2: yibei
//description: EECS 183 peroject 3 cipher test file

#include <iostream>
#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <string>

using namespace std;


void testShiftAlphaCharacter();

void startTests() {
    testShiftAlphaCharacter();
    // Repeat for all other functions to be tested

    
    return;
}

void testShiftAlphaCharacter() {
    cout << "Now testing function ShiftAlphaCharacter()" << endl;
    cout << "Expected: 'a', Actual: '" << shiftAlphaCharacter('a', 0) << "'" << endl;
    cout << "Expected: 'b', Actual: '" << shiftAlphaCharacter('a', 1) << "'" << endl;
    cout << "Expected: 'd', Actual: '" << shiftAlphaCharacter('b', 2) << "'" << endl;
    return;
}

