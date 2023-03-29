/*
Program 6 - One Turn
Iftiaz Ahmed Alfi

29th March, 2023
*/ 

#ifndef DICE_HPP
#define DICE_HPP
#include "tools.hpp"

class Dice {
private: 
    int nDice;
    int *diceArray;
    array<int, 2> pairSums;
public:
    //------------------------------------Constuctors
    Dice(int n);
    ~Dice() { delete[] diceArray; };

    //------------------------------------Prototypes
    const int *roll();
    void makePair();
    array<int, 2> getPairSums();
    ostream& print(ostream& out);
};

inline ostream& operator<< (ostream& out, Dice& D) {
    return D.print( out );
}

#endif