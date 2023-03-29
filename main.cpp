/*
Program 6 - One Turn
Iftiaz Ahmed Alfi

29th March, 2023
*/ 

#include "tools.hpp"
#include "game.hpp"
#include "board.hpp"
#include "player.hpp"

//-------------------------testGame()
void testGame(Game obj) {
    cout <<"--------------------------UNIT TEST START" <<endl;
    obj.playGame();
    cout <<"--------------------------UNIT TEST END" <<endl;
}

//---------------------------main()
int main() { 
    banner();

    Game gameObj;
    testGame(gameObj);

    bye();
}