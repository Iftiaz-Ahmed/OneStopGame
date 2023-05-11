/*
Program 13
Iftiaz Ahmed Alfi

11th May, 2023
*/ 

#include "player.hpp"

bool Player::   //----------------- wonColumn function
wonColumn(int colNum) { 
    if (score < 4) {
        scoreboard[score] = colNum;
        score++;
    }
    return score == 3;
}

ostream& Player::   //------------- print function
print(ostream& out) {
    out << name <<" " <<words[(int)color] <<" " <<score <<endl;

    return out;
}