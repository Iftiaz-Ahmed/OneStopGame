/*
Program 4 - Game
Iftiaz Ahmed Alfi and Anwar Haq

22nd Feb, 2023
*/ 

#include "column.hpp"

int Column::columnLengths[13] = {0, 0, 3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3};

Column::  //------------------------------------------------------ Constructor of Column
Column(int colNum) {
    columnNo = colNum;
    columnContents = new int*[columnLengths[colNum]];

    for (int m=0; m<columnLengths[columnNo]; m++) {
        columnContents[m] = new int[5];
    }

    for (int m=0; m<columnLengths[columnNo]; m++) {
        for (int n=0; n<5; n++) {
            columnContents[m][n] = -1;
        }
    }

}

Column::  //------------------------------------------------------ Destructor of Column
~Column() {
    for (int m=0; m<columnLengths[columnNo]; m++) {
        delete [] columnContents[m];
    }
    delete [] columnContents;
}


ostream& Column::   //-------------------------------------------------- print function
print(ostream& out) {
    out <<columnNo <<" ";
    out <<cState[(int)columnState] <<" ";
    
    for (int m=0; m<columnLengths[columnNo]; m++) {
        for (int n=0; n<5; n++) {
            int tile = columnContents[m][n];
            if (tile > -1) {
                out <<symbols[tile];
            } else {
                out <<"_";
            }
        }
        out <<"  ";
    }
    out <<"\n";

    return out;
}

bool Column::   //-------------------------------------------------- startTower() function
startTower(Player* p) {
    int color = (int) p->getColor();
    bool flag = true;

    for (int m=0; m<columnLengths[columnNo]; m++) {
        if (color == columnContents[m][color]) {
            columnContents[m][color] = -1;
            currentPos = m;
            flag = true;
            break;
        } else if (columnContents[m][0] == 0) {
            flag = false;
            break;
        }
    }

    return flag;
}

bool Column::   //------------------------------------------------------- move() function
move() {
    bool flag = false;
    currentPos += 1;

    if (columnState == ColumnState::available) {
        if (currentPos-1 > -1)
            columnContents[currentPos-1][0] = -1;
        
        columnContents[currentPos][0] = 0;
        // if tower in the last square
        if (currentPos == columnLengths[columnNo]-1) {  
             // setting state to pending   
            columnState = ColumnState::pending;         
        }
        flag = true;
    } 
    
    return flag;
}

void Column::   //-------------------------------------------------- stop() function
stop(Player* p) {
    int color = (int) p->getColor();
    bool flag = false;
    int idxPos = -1;

    for (int m=0; m<columnLengths[columnNo]; m++) {
        if (columnContents[m][0] == 0) {
            columnContents[m][0] = -1;
            columnContents[m][color] = color;
            break;
        }
    }

    if (columnState == ColumnState::pending) {
        columnState = ColumnState::captured;
        p->wonColumn(columnNo);
    }
}
