/*
Program 8 - List Template
Iftiaz Ahmed Alfi

12th April, 2023
*/ 

#ifndef GAME_HPP 
#define GAME_HPP
#include "tools.hpp"
#include "dice.hpp"
#include "player.hpp"
#include "column.hpp"
#include "board.hpp"
#include "enums.hpp"

class Game
{
private:
    Dice* diceSet;
    bool colorsUsed[5] = {true, false, false, false, false};
    Player* player = getNewPlayer();
    Board gameBoard = Board();
public:
    //------------------------------------------Constuctors
    Game() : diceSet(new Dice(4)) { };
    ~Game() { delete diceSet; };

    //-----------------------------------------Prototypes
    Player* getNewPlayer();
    void oneTurn(Player* pp);

    //----------------------------------------Testing purpose
    void playGame();
};

#endif