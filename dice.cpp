/*
Program 8 - List Template
Iftiaz Ahmed Alfi

12th April, 2023
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

  //----------------------IndexPair struct
struct IndexPair {
    int a;
    int b;
};

  //-------------------------validatePair()
IndexPair validatePair(int* diceArray) {
    char a, b;
    map<char, int> options = {{'a', 0}, {'b', 1}, {'c', 2}, 
        {'d', 3}};
    for(const auto& m : options) 
        cout <<m.first <<"->" <<diceArray[m.second] <<" ";

    while (true) {
        cout <<endl <<": ";
        cin >> a >> b;
        if (a == b) 
            cout <<"Both letters cannot be same. Try again!";
        else if (options[a] < 0 || options[b] < 0 
            || options[a] > 3 || options[b] > 3)
            cout <<"Wrong letter picked. Try again!";
        else break;
    }
    IndexPair values = {options[a], options[b]};
    return values;
}

void Dice:: //-------------------------choosePair()
makePair() {
    //Lets assume there will be 2 pairs only
    IndexPair firstPair;
    int firstSum = 0; 
    int secondSum = 0;
    cout <<"Choose letters to make pair: " <<endl;
    firstPair = validatePair(diceArray);

    for (int m=0; m<4; m++) {
        if (m == firstPair.a || m == firstPair.b) 
            firstSum += diceArray[m];
        else secondSum += diceArray[m];
    }
    pairSums[0] = firstSum;
    pairSums[1] = secondSum;
}

array<int, 2> Dice::getPairSums() { //-----getPairSums()
    return pairSums;
}

ostream& Dice::   //------------------------print()
print(ostream& out) {
    if (diceArray != NULL) {
        for (int i = 0; i < nDice; i++) out << diceArray[i] << " ";
        out << endl;
    }
    return out;
}
