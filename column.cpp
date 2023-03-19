/*
Program 5 - Board
Iftiaz Ahmed Alfi and Anwar Haq

18th March, 2023
*/ 

#include "column.hpp"

int Column::columnLengths[13] = {0, 0, 3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3};

ostream& Column::   //---------------- print function
print(ostream& out) {
    out <<columnNo <<" " <<cState[(int)columnState] <<" ";
    
    for (int m=0; m<columnLength; m++) {
        for (int n=0; n<5; n++) {
            if (m == columnContents[n]) out <<symbols[n];
            else out <<"_";
        }
        out <<"  ";
    }
    out <<"\n";

    return out;
}

bool Column::   //--------------- startTower() function
startTower(Player* p) {
    int color = (int) p->getColor();

    if (columnState == ColumnState::available) {
        if (columnContents[color] > -1) {
            columnContents[0] = columnContents[color];
            columnContents[color] = -1;
        }
        return true;
    } else {
        return false;
    }
}

bool Column::   //----------------- move() function
move() {
    if (columnState == ColumnState::available) {
        if (columnContents[0] > -1) {
            columnContents[0] += 1;
        } else {
            columnContents[0] = 0;
        }

        if (columnContents[0] == columnLength-1) {  
            columnState = ColumnState::pending;    
        }
        return true;
    } else {
        return false;
    }
}

void Column::   //---------------- stop() function
stop(Player* p) {
    int color = (int) p->getColor();

    if (columnState != ColumnState::captured) {
        columnContents[color] = columnContents[0];
        columnContents[0] = -1;

        if (columnState == ColumnState::pending) {
            columnState = ColumnState::captured;
            p->wonColumn(columnNo);
        } 
    }
}