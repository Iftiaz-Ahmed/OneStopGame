/*
Program 13
Iftiaz Ahmed Alfi

11th May, 2023
*/ 

#include "board.hpp"

Board::  //------------------------------Constructor
Board() {
    for (int n=0; n<13; n++) {
        if (n < 2) backBone[n] = nullptr;
        else backBone[n] = new Column(n);
    }
}

void Board::  //--------------------------startTurn
startTurn(Player* player) {
    currentPlayer = player;
    towerCounter = 0;
    for (int m=0; m<3; m++) inUseTowers[m] = 0;
}

bool Board::  //----------------------------move
move(const int column) {
    if (column < 2) return false;
    bool flag = false;

    for (int m : inUseTowers) {
        if (m == column) {
            flag = true;
            break;
        } 
    }
   
    if ( backBone[column]->state() != ColumnState::available) 
        return false;

    if (!flag && towerCounter == 3) return false;
    else {
        if(!flag) {
            towerCounter++;
            inUseTowers[towerCounter-1] = column; 
        }
        backBone[column]->startTower(currentPlayer);
        backBone[column]->move();

        return true;
    }
}

void Board::  //----------------------------stop
stop() {
    for (int m=0; m<3; m++) 
        if (inUseTowers[m] > 1) 
            backBone[inUseTowers[m]]->stop(currentPlayer);
}

void Board::  //----------------------------bust
bust() {
    for (int m=0; m<3; m++)
        if (inUseTowers[m] > 1) backBone[inUseTowers[m]]->bust();
    towerCounter = 0;
}

ostream& Board::  //------------------------print
print(ostream& out) {
    for (int m = 2; m<13; m++) backBone[m]->print(cout);

    return out;
}

void Board::  //------------------------clearBoard()
clearBoard() {
    towerCounter = 0;
    currentPlayer = nullptr;
    for (int m = 0; m < 3; m++) inUseTowers[m] = 0;
    for (int m = 2; m < 13; m++) {
        delete backBone[m];
        backBone[m] = new Column(m);
    }
}