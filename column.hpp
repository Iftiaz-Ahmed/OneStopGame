/*
Program 8 - List Template
Iftiaz Ahmed Alfi

12th April, 2023
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
    int columnLength;
    ColumnState columnState = ColumnState::available;
    int columnContents[5] = {-1, -1, -1, -1, -1};
public:
    //----------------------------Constuctors
    Column(int colNum) : columnNo(colNum), columnLength(columnLengths[columnNo]) { }
    ~Column() = default;
    
    //----------------------------Prototypes
    ColumnState state() { return columnState; };
    bool startTower(Player* player);
    bool move();
    void stop(Player* player);
    void bust() {for (int m=0; m<5; m++) columnContents[m] = -1;};
    ostream& print(ostream& out);
};

inline ostream& operator<< (ostream& out, Column& C) {
    return C.print( out );
}

#endif
