/*
Program 5 - Board
Iftiaz Ahmed Alfi and Anwar Haq

18th March, 2023
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