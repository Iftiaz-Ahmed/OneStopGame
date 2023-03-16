/*
Program 4 - Game
Iftiaz Ahmed Alfi and Anwar Haq

22nd Feb, 2023
Resubmitted: 15th March, 2023
*/ 

#include "tools.hpp"
#include "game.hpp"

//---------------------------------------------testGame()
void testGame(Game obj) {
    cout <<"------------------------------UNIT TEST START" <<endl;
    obj.playGame();
    cout <<"------------------------------UNIT TEST END" <<endl;
}

//--------------------------------------------main()
int main() { 
    banner();

    Game gameObj = Game();
    testGame(gameObj);

    bye();
}