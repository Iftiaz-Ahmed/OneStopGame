#ifndef BOARD_HPP
#define BOARD_HPP
#include "tools.hpp" 
#include "column.hpp"
#include "player.hpp"

class Board {
private:
	int towerCounter;
	int inUseTowers[3];
	Column* backBone[13];
	Player* currentPlayer;

public:
	//------------------------------------------Constructors
	Board();
	~Board();

	//------------------------------------------Prototypes
	void startTurn(Player* player);
	bool move(int column);
	void stop();
	void bust();
	ostream& print(ostream& out);
	
};

inline ostream& operator<< (ostream& out, Board& B) {
    return B.print( out );
}



#endif