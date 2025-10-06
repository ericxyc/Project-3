/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Yancheng Xiang
 * ericxyc
 *
 * EECS 183: Project 3
 * Winter 2025
 *
 * EECS 183 Project 3 cipher
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

//************************************************************************
// Implement the functions below this line.
//************************************************************************

void ciphers() {
    // ask user for cipher (Caesar, Vigenere, or Polybius)
    string cipherType;
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    cin >> cipherType;
    char typeArr[cipherType.size()];
    string cipherType1 = "";
    int cvp;
    
    for (int i = 0; i < cipherType.size(); ++i) {
        typeArr[i] = toupper(cipherType.at(i));
        cipherType1 += typeArr[i];
    }
    if (cipherType1 == "C" || cipherType1 == "CAESAR") {
        cvp = 1;
    }
    else if (cipherType1 == "V" || cipherType1 == "VIGENERE") {
        cvp = 2;
    }
    else if (cipherType1 == "P" || cipherType1 == "POLYBIUS") {
        cvp = 3;
    }
    else {
        cout << "Invalid cipher!" << endl;
        return;
    }
    
    
    
    // ask user to encrypt or decrypt
    string enDe;
    cout << "Encrypt or decrypt: ";
    cin >> enDe;
    char modeArr[enDe.size()];
    string enDe1 = "";
    bool eord;
    
    for (int i = 0; i < enDe.size(); ++i) {
        modeArr[i] = toupper(enDe.at(i));
        enDe1 += modeArr[i];
    }
    if (enDe1 == "E" || enDe1 == "ENCRYPT") {
        eord = true;
    }
    else if (enDe1 == "D" || enDe1 == "DECRYPT") {
        eord = false;
    }
    else {
        cout << "Invalid mode!" << endl;
        return;
    }
        
    // get message from user
    string message;
    string ws1;
    cout << "Enter a message: ";
    getline(cin,ws1);
    getline(cin, message);
    
    bool mesVal = true;
    string validMes = "";
    char mesArr[message.size()];
    
    //check message for polybius
    if (cvp == 3) {
        for (int i = 0; i < message.size(); ++i) {
            if (!(isalnum(message.at(i)) || isspace(message.at(i)))){
                mesVal = false;
            }
        }
        if (mesVal == false) {
            cout << "Invalid message!" << endl;
            return;
        }
        //to upper case
        else {
            for (int i = 0; i < message.size(); ++i) {
                mesArr[i] = toupper(message.at(i));
                validMes += mesArr[i];
            }

        }
    }

    // get key or keyword from user
    int key1 = 0;
    string key;
    string ws2;
    cout << "What is your key: ";
    if (cvp == 1) {
        cin >> key1;
    }
    else{
        getline(cin, key);
    }
    
    //ckeck key when vigenere
    bool keyVal2 = false;
    string validKey2;
    char keyArr1[key.size()];
    if (cvp == 2) {
        for (int i = 0; i < key.size(); ++i){
            if (isalpha(key.at(i))) {
                keyVal2 = true;
            }
        }
        if (keyVal2 == true) {
            //remove nonalphas
            for (int i = 0; i < key.size(); ++i){
                if (!isalpha(key.at(i))) {
                    key = removeNonAlphas(key);
                }
            }
            //to upper case
            for (int i = 0; i < key.size(); ++i) {
                keyArr1[i] = toupper(key.at(i));
                validKey2 += keyArr1[i];
            }
        }
        else {
            cout << "Invalid key!" << endl;
            return;
        }
    }
    
    //check key when polybius
    bool keyVal3 = true;
    string validKey3;
    char keyArr2[key.size()];
    if (cvp == 3) {
        for (int i = 0; i < key.size(); ++i){
            if (!isalnum(key.at(i))) {
                keyVal3 = false;
            }
        }
        if (keyVal3 == true) {
            for (int i = 0; i < key.size(); ++i) {
                keyArr2[i] = toupper(key.at(i));
                validKey3 += keyArr2[i];
            }
            validKey3 = removeDuplicate(validKey3);
        }
            
        else {
            cout << "Invalid key!" << endl;
            return;
        }
        
    }
    
    // encrypt or decrypt message using selected cipher and key(word)
    char grid1 [SIZE][SIZE];
    if (cvp == 1 && eord) {
        cout << "The encrypted message is: " << caesarCipher(message, key1, eord) << endl;
    }
    else if (cvp == 1 && !eord) {
        cout << "The decrypted message is: " << caesarCipher(message, key1, eord) << endl;
    }
    else if (cvp == 2 && eord) {
        cout << "The encrypted message is: " << vigenereCipher(message, validKey2, eord) << endl;
    }
    else if (cvp == 2 && !eord) {
        cout << "The decrypted message is: " << vigenereCipher(message, validKey2, eord) << endl;
    }
    else if (cvp == 3 && eord) {
        cout << "The encrypted message is: " << polybiusSquare(grid1, validKey3, validMes, eord) << endl;
    }
    else if (cvp == 3 && !eord) {
        cout << "The decrypted message is: " << polybiusSquare(grid1, validKey3, validMes, eord) << endl;
    }
    
    // print encrypted/decrypted message

    return;
}
