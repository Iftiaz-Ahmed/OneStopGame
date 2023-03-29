/*
Program 6 - One Turn
Iftiaz Ahmed Alfi

29th March, 2023
*/ 

#ifndef GAME_HPP 
#define GAME_HPP
#include "tools.hpp"
#include "dice.hpp"
#include "player.hpp"
#include "column.hpp"
#include "board.hpp"
#include "enums.hpp"

using namespace std;

class Game
{
private:
    Dice *diceSet;
    int colorsUsed[5];
    Player player;
    Board gameBoard;
public:
    //------------------------------------------Constuctors
    Game() : diceSet(new Dice(4)), colorsUsed{1, 0, 0, 0, 0}, 
             player(getNewPlayer()), gameBoard(Board()) { };
    ~Game() { delete diceSet; };

    //-----------------------------------------Prototypes
    Player getNewPlayer();
    void oneTurn(Player* pp);

    //----------------------------------------Testing purpose
    void playGame();
};

#endif