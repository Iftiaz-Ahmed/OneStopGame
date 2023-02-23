/*
Program 4 - Game
Iftiaz Ahmed Alfi and Anwar Haq

22nd Feb, 2023
*/ 

#ifndef COLUMN_HPP
#define COLUMN_HPP
#include "tools.hpp" 
#include "enums.hpp"
#include "player.hpp"

class Column {
private:
    static int columnLengths[13];
    int columnNo;
    ColumnState columnState = ColumnState::available;
    int** columnContents;
    int currentPos = -1;
public:
    //------------------------------------------------------------------Constuctors
    Column(int colNum);
    ~Column();
    
    //------------------------------------------------------------------Prototypes
    ColumnState state() { return columnState; };
    bool startTower(Player* player);
    bool move();
    void stop(Player* player);
    void bust() {};
    ostream& print(ostream& out);

    //------------------------------------------------------------------Testing purpose
    void setState(ColumnState s) { columnState = s; };
};

inline ostream& operator<< (ostream& out, Column& C) {
    return C.print( out );
}

#endif
