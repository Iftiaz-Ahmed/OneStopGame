/*
Program 11 - A Whole Game
Iftiaz Ahmed Alfi

3rd May, 2023
*/ 

#include "tools.hpp"
#include "player.hpp"
#include "game.hpp"

//---------------------------main()
int main() { 
    banner();
    /*
    To play the real game change 'diceSet(new FakeDice())' in game.hpp
    to 'diceSet(new CantStopDice())'
    */

    Game gameObj = Game();
    gameObj.play();
    bye();
}