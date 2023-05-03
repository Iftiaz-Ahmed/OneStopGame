/*
Program 11 - A Whole Game
Iftiaz Ahmed Alfi

3rd May, 2023
*/ 

#include "dice.hpp"
#include "badChoice.hpp"

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
    IndexPair values = {};
    map<char, int> options = {{'a', 0}, {'b', 1}, {'c', 2}, 
        {'d', 3}};
    for(const auto& m : options) 
        cout <<m.first <<"->" <<diceArray[m.second] <<" ";
    cin.ignore(); 
    char* choice = new char[20];
    for (;;) {
        try {
            cout <<"\n: ";
            cin.getline(choice, 20);    

            for (int m = 0; m < strlen(choice); m++) {
                if (strchr("abcd ", choice[m]) == NULL) throw BadSlot(choice);
                else if (choice[m] != ' ') {
                    if (m==0) values.a = options[choice[m]];
                    else values.b = options[choice[m]];
                }
            }
            if (values.a == values.b) throw DuplicateSlot(choice);
            else break;
        } catch (BadChoice& bc) { bc.print(); }
    }
    delete[] choice;
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
        cout <<line <<endl;
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
