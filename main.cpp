/*
Program 10 - Exception
Iftiaz Ahmed Alfi

29th April, 2023
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