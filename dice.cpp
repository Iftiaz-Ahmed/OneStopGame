/*
Program 5 - Board
Iftiaz Ahmed Alfi and Anwar Haq

18th March, 2023
*/ 

#include "dice.hpp"

Dice::  //----------------------------Constructor
Dice(int n) {
    
    if (n > 0 && n < 11) {
        nDice = n;
        diceArray = new int[n];
    }
    else {
        nDice = 0;
        diceArray = NULL;
        cout << "Number of Dice must be between 1 and 10." << endl;
    }

    srand(time(NULL));
}


const int *Dice::  //-------------------------roll()
roll() {
    for (int m = 0; m < nDice; m++) {
        diceArray[m] = 1 + rand() % 6;
    }

    return diceArray;
}

ostream& Dice::   //------------------------print()
print(ostream& out) {
    if (diceArray != NULL) {
        for (int i = 0; i < nDice; i++) out << diceArray[i] << " ";
        out << endl;
    }

    return out;
}
