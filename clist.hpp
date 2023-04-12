/*
Program 7 - Player List
Iftiaz Ahmed Alfi

10th April, 2023
*/ 

#ifndef CLIST_HPP
#define CLIST_HPP
#include "player.hpp"

template <class Item>
//------------------------------------CList Class
class CList{
private:
    //------------------------------------Cell Class
    class Cell{
    public:
        Item item;
        Cell* next;
        Cell* prev;
        // ---------------------------------Constructors 
        Cell(Item i) : item(i), next(nullptr), prev(nullptr) { };
        ~Cell() { delete item; };
    };
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
    void addCell(Item it);
    void init() { (empty()) ? current = nullptr : current = head; };
    Cell* next();
    void remove();
    //-----------------------------------For Testing purpose
    Item getItem() { return current->item; }
};

template <class Item>
inline ostream& operator<< (ostream& out, CList<Item>& C) {
    return C.print( out );
}

//--------------------------------------Function Definitions

template <class Item>
CList<Item>:: //-------------------------------Destructor
~CList() {
    Cell* temp = head;
    while (temp != nullptr) {
        Cell* next = temp->next;
        delete temp;
        temp = next;
    }
}

template <class Item>
void CList<Item>:: //---------------------------addCell()
addCell(Item it) {
    Cell* newCell = new Cell(it);
    if (empty()) {
        head = newCell;
        tail = newCell;
        current = newCell;
    } else {
        current->next = newCell;
        newCell->prev = current;
        newCell->next = head;
        tail = newCell;
        current = tail;
    }
    cellCount++;
}

template <class Item>
void CList<Item>:: //-----------------------------remove()
remove() {
    Cell* temp = current;
    if (head == current) {
        current = current->next;
        head = current;
        tail->next = head;
    } else {
        temp->prev->next = current->next;
        current = temp->next;
    }
    delete temp;
    cellCount--;
}

template <class Item>
typename CList<Item>::Cell* CList<Item>::  //----- next()
next() {
    if (empty() || current->next == nullptr) return nullptr;
    else {
        current = current->next;
        return current;
    }
}

template <class Item>
ostream& CList<Item>::   //--------- print function
print(ostream& out) {
    if (empty()) out <<"Empty List!" <<endl;
    else {
        current = head;
        do {
            out <<*(current->item);
            current = current->next;
        } while (current != head);
    }
    return out;
}

#endif