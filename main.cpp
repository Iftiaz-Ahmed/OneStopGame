/*
Program 4 - Game
Iftiaz Ahmed Alfi and Anwar Haq

22nd Feb, 2023
*/ 

#include "tools.hpp"
#include "game.hpp"
#include "board.hpp"
#include "player.hpp"

//--------------------------------------------------------------------testGame()
void testGame(Game obj) {
    cout <<"-----------------------------------------UNIT TEST START" <<endl;
    obj.playGame();
    cout <<"-----------------------------------------UNIT TEST END" <<endl;
}

//--------------------------------------------------------------------main()
int main() { 
    banner();

    // Game gameObj;
    // testGame(gameObj);

    Board boardObj = Board();
    // cout <<boardObj;

    Player playerObj = Player("Alice", ECcolor::blue);

    boardObj.startTurn(&playerObj);
    boardObj.move(3);
    boardObj.move(9);
    boardObj.move(2);
    boardObj.stop();

    boardObj.startTurn(&playerObj);
    boardObj.move(2);
    boardObj.move(5);
    boardObj.move(4);
    boardObj.stop();

    boardObj.startTurn(&playerObj);
    boardObj.move(2);
    boardObj.move(5);
    boardObj.move(4);
    boardObj.stop();

    cout << playerObj;

    cout <<boardObj;
    

    bye();
}