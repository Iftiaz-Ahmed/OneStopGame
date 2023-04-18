/*
Program 9 - Polymorphic Dice
Iftiaz Ahmed Alfi

17th April, 2023
*/ 

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "tools.hpp"
#include "enums.hpp"

class Player {
private:
    string name;
    ECcolor color;
    int score;
    int scoreboard[3];
public:
    //--------------------------Constuctors
    Player(string n, ECcolor c) : name(n), color(c), score(0) {}
    ~Player() = default;

    //--------------------------Prototypes
    ECcolor getColor() { return color; };
    int getScore() { return score; }; 
    bool wonColumn(int colNum);
    ostream& print(ostream& out);
};

inline ostream& operator<< (ostream& out, Player& P) {
    return P.print( out );
}

#endif