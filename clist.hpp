/*
Program 7 - Player List
Iftiaz Ahmed Alfi

10th April, 2023
*/ 

#ifndef CLIST_HPP
#define CLIST_HPP
#include "player.hpp"

class Clist;

//------------------------------------Cell Class
class Cell{
friend class CList;
private:
    Player* player;
    Cell* next;
    Cell* prev;
    // ---------------------------------Constructors 
    Cell(Player* p) : player(p), next(nullptr) { };
    ~Cell() { delete player; };
};

//------------------------------------CList Class
class CList{
private:
    int cellCount;
    Cell* head;
    Cell* tail;
    Cell* current;
public:
    //------------------------------------Constuctors
    CList() : cellCount(0), head(nullptr), tail(nullptr), current(nullptr) { };
    ~CList();
    //------------------------------------Prototypes
    int count() { return cellCount; }
    bool empty() { return (cellCount > 0) ? false : true; }
    ostream& print(ostream& out);
    void addCell(Player* it);
    void init() { (empty()) ? current = nullptr : current = head; };
    Cell* next();
    void remove();
    //-----------------------------------For Testing purpose
    Player getCurrentPlayer() { return *current->player; }
};

inline ostream& operator<< (ostream& out, CList& C) {
    return C.print( out );
}

#endif