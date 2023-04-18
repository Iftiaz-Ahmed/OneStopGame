/*
Program 9 - Polymorphic Dice
Iftiaz Ahmed Alfi

17th April, 2023
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


const int* Dice::  //---------------------Dice roll() 
roll() {
    for (int m = 0; m < nDice; m++) diceArray[m] = 1 + rand() % 6;
    return diceArray;
}

  //----------------------IndexPair struct
struct IndexPair {
    int a;
    int b;
};

  //-------------------------validatePair()
IndexPair validatePair(const int* diceArray) {
    char a, b;
    map<char, int> options = {{'a', 0}, {'b', 1}, {'c', 2}, 
        {'d', 3}};
    for(const auto& m : options) 
        cout <<m.first <<"->" <<diceArray[m.second] <<" ";
    for(;;) {
        cout <<endl <<": "; cin >> a >> b;
        if (a == b)  
            cout <<"Both letters cannot be same. Try again!";
        else if ( options.find(a) == options.end() || options.find(b) == options.end() )
            cout <<"Wrong letter picked. Try again!";
        else break;
    }
    IndexPair values = {options[a], options[b]};
    return values;
}

  //----------------------------------makePair()
int* makePair(const int* diceArray) {
    //Lets assume there will be 2 pairs only
    IndexPair firstPair;
    int* sums = new int[2];
    int firstSum = 0; 
    int secondSum = 0;
    cout <<"Choose letters to make pair: " <<endl;
    firstPair = validatePair(diceArray);

    for (int m=0; m<4; m++) {
        if (m == firstPair.a || m == firstPair.b) 
            firstSum += diceArray[m];
        else secondSum += diceArray[m];
    }
    sums[0] = firstSum;
    sums[1] = secondSum;
    return sums;
}

const int* CantStopDice::  //--------CantStopDice roll()
roll() {
    const int* diceValues = Dice::roll();
    Dice::print(cout);
    const int* sumOfPairs = makePair(diceValues);
    pairSums[0] = sumOfPairs[0];
    pairSums[1] = sumOfPairs[1];
    return pairSums;
}

const int* FakeDice::  //------------FakeDice roll()
roll() {
    static int rollPairs[2];
    string line;
    if (getline(diceFile, line)) {
        stringstream ss(line);
        int first, second, third, fourth;
        ss >> first >> second >> third >> fourth;
        rollPairs[0] = first + second;
        rollPairs[1] = third + fourth;
    } else fatal("End of line reached!");
    return rollPairs;
}

ostream& Dice::   //-----------------print()
print(ostream& out) {
    if (diceArray != NULL) {
        for (int i = 0; i < nDice; i++) out << diceArray[i] << " ";
        out << endl;
    }
    return out;
}
