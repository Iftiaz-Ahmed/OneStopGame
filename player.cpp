/*
Program 6 - One Turn
Iftiaz Ahmed Alfi

29th March, 2023
*/ 

#include "player.hpp"

bool Player::   //----------------- wonColumn function
wonColumn(int colNum) { 
    scoreboard[score] = colNum;
    score++;

    return score == 3;
}

ostream& Player::   //------------- print function
print(ostream& out) {
    out << name <<" " <<words[(int)color] <<" " <<score <<endl;

    return out;
}