#include "board.hpp"

Board::  //-----------------------------------------Constructor
Board() : towerCounter(0), currentPlayer(nullptr) {

    for (int n=0; n<13; n++) {
        if (n < 2) {
            backBone[n] = nullptr;
        } else {
            backBone[n] = new Column(n);
        }
    }
}

Board::  //-----------------------------------------Destructor
~Board() {
    for (int n=2; n<13; n++) {
        delete backBone[n];
    }
}

void Board::  //------------------------------------startTurn
startTurn(Player* player) {
    // not done yet
    currentPlayer = player;

    for (int m=0; m<3; m++) {
        inUseTowers[m] = 0;
    }

    for (int m=0; m<3; m++) {
        if (inUseTowers[m] > 0)
            towerCounter++;
    }
}

bool Board::  //------------------------------------move
move(int column) {
    bool flag = false;

    if ( backBone[column]->state() == ColumnState::pending || backBone[column]->state() == ColumnState::captured && towerCounter == 0) {
        return false;
    }

    flag = backBone[column]->startTower(currentPlayer);
    
    if (flag) {
        backBone[column]->move();
        return true;
    } else {
        return false;
    }
}

void Board::  //------------------------------------stop
stop() {
    for (int m=0; m<3; m++) {
        if (inUseTowers[m] > 1) {
            backBone[inUseTowers[m]]->stop(currentPlayer);
        }
    }
}

void Board::  //------------------------------------bust
bust() {
    for (int m=0; m<3; m++) {
        if (inUseTowers[m] > 1) {
            backBone[inUseTowers[m]]->bust();
        }
    }
}

ostream& Board::  //--------------------------------print
print(ostream& out) {
    for (int m = 2; m<13; m++) {
        backBone[m]->print(cout);
    }

    return out;
}