/*
Program 10 - Exception
Iftiaz Ahmed Alfi

29th April, 2023
*/ 

#ifndef GAME_HPP 
#define GAME_HPP
#include "tools.hpp"
#include "dice.hpp"
#include "player.hpp"
#include "column.hpp"
#include "board.hpp"
#include "clist.hpp"
#include "enums.hpp"

class Game
{
private:
    Dice* diceSet;
    bool colorsUsed[5] = {true, false, false, false, false};
    CList<Player*> playerList;
    Board gameBoard = Board();
    bool checkData(char* name, char* color);
public:
    //------------------------------------------Constuctors
    Game() : diceSet(new CantStopDice()) { 
        for (int m=0; m<2; m++) playerList.addCell(getNewPlayer()); };
    ~Game() { delete diceSet; };

    //-----------------------------------------Prototypes
    Player* getNewPlayer();
    void oneTurn(Player* pp);

    //----------------------------------------Testing purpose
    void playGame();
};

#endif