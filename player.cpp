/*
Program 4 - Game
Iftiaz Ahmed Alfi and Anwar Haq

22nd Feb, 2023
*/ 

#include "player.hpp"

bool Player::   //------------------------------------------------ wonColumn function
wonColumn(int colNum) { 
    scoreboard[score] = colNum;
    score++;

    return score == 3;
}

ostream& Player::   //---------------------------------------- --- print function
print(ostream& out) {
    out << name <<" " <<words[(int)color] <<" " <<score <<endl;

    return out;
}