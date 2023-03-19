/*
Program 5 - Board
Iftiaz Ahmed Alfi and Anwar Haq

18th March, 2023
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