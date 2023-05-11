/*
Program 13
Iftiaz Ahmed Alfi

11th May, 2023
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

class Game {
private:
    Dice* diceSet;
    CList<Player*> playerList;
    Board gameBoard = Board();
    GameState gameState;
    const int* dicePairs;
    bool checkData(char* name, char* color);
    void setPlayers();
public:
    //------------------------------------------Constuctors
    Game() : diceSet(new FakeDice()), gameState(GameState::begun) { setPlayers(); };
    ~Game() { delete diceSet; };

    //-----------------------------------------Prototypes
    Player* getNewPlayer();
    void oneTurn(Player* pp);
    void play();
};


#endif