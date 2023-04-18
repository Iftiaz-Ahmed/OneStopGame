/*
Program 9 - Polymorphic Dice
Iftiaz Ahmed Alfi

17th April, 2023
*/ 

#include "tools.hpp"
#include "player.hpp"
#include "game.hpp"

//---------------------------main()
int main() { 
    banner();
    Game gameObj = Game();
    gameObj.playGame();
    bye();
}