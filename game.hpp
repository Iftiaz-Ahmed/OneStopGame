/*
Program 4 - Game
Iftiaz Ahmed Alfi and Anwar Haq

22nd Feb, 2023
Resubmitted: 15th March, 2023
*/ 

#ifndef GAME_HPP 
#define GAME_HPP
#include "tools.hpp"
#include "dice.hpp"
#include "player.hpp"
#include "column.hpp"
#include "enums.hpp"

using namespace std;

class Game
{
private:
    Dice *diceSet;
    int colorsUsed[5];
    Player player1;
    Player player2;
    Column column2{2};
    Column column7{7};
public:
    //------------------------------------------Constuctors
    Game() : diceSet(new Dice(4)), colorsUsed{1, 0, 0, 0, 0}, 
             player1(getNewPlayer()), player2(getNewPlayer()) { };
    ~Game() { delete diceSet; };

    //-----------------------------------------Prototypes
    Player getNewPlayer();

    //----------------------------------------Testing purpose
    void playGame();
};

#endif