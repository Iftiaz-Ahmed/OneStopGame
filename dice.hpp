/*
Program 10 - Exception
Iftiaz Ahmed Alfi

29th April, 2023
*/ 

#ifndef DICE_HPP
#define DICE_HPP
#include "tools.hpp"

#define FAKE_DICE_FILE "fake_dice.txt"

//---------------------Dice Class (Parent)
class Dice {
private: 
    int nDice;
    int* diceArray;
public:
    //------------------------------------Constuctors
    Dice(int n);
    virtual ~Dice() { delete[] diceArray; };

    //------------------------------------Prototypes
    virtual const int* roll();
    int getDiceNum() { return nDice; };
    int* getDiceArray() { return diceArray; }; 
    ostream& print(ostream& out);
};

inline ostream& operator<< (ostream& out, Dice& D) {
    return D.print( out );
}

//---------------------CantStopDice Class
class CantStopDice : public Dice {
private:
    int pairSums[2];
public:
    //------------------------------------Constuctors
    CantStopDice() : Dice(4), pairSums{0, 0} {}
    virtual ~CantStopDice() {}
    
    //------------------------------------Prototypes
    const int* roll() override;
};

//---------------------FakeDice Class
class FakeDice : public CantStopDice {
private:
    ifstream diceFile;
public:
    //------------------------------------Constuctors
    FakeDice() : CantStopDice() {
        diceFile.open(FAKE_DICE_FILE);
        if (!diceFile.is_open()) fatal("Unable to open: " + string(FAKE_DICE_FILE));
    }
    virtual ~FakeDice() { diceFile.close(); }

    //------------------------------------Prototypes
    const int* roll() override;
};

#endif