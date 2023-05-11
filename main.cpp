/*
Program 13
Iftiaz Ahmed Alfi

11th May, 2023
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