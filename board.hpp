/*
Program 9 - Polymorphic Dice
Iftiaz Ahmed Alfi

17th April, 2023
*/ 

#ifndef BOARD_HPP
#define BOARD_HPP
#include "tools.hpp" 
#include "column.hpp" 
#include "player.hpp"

class Board {
private:
	int towerCounter = 0;
	int inUseTowers[3] = {0, 0, 0};
	Column* backBone[13];
	Player* currentPlayer = nullptr;

public: 
	//------------------------------Constructors
	Board();
	~Board() { for (int n=2; n<13; n++) delete backBone[n]; };

	//------------------------------Prototypes
	void startTurn(Player* player);
	bool move(int column);
	void stop();
	void bust();
	ostream& print(ostream& out);
	
	//------------------------------Testing purpose
	void clearBoard();
};

inline ostream& operator<< (ostream& out, Board& B) {
    return B.print( out );
}

#endif