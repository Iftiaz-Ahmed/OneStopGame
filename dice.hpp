/*
Program 5 - Board
Iftiaz Ahmed Alfi and Anwar Haq

18th March, 2023
*/ 

#ifndef DICE_HPP
#define DICE_HPP
#include "tools.hpp"

class Dice {
private: 
    int nDice;
    int *diceArray;

public:
    //------------------------------------Constuctors
    Dice(int n);
    ~Dice() { delete[] diceArray; };

    //------------------------------------Prototypes
    const int *roll();
    ostream& print(ostream& out);
};

inline ostream& operator<< (ostream& out, Dice& D) {
    return D.print( out );
}

#endif