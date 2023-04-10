/*
Program 7 - Player List
Iftiaz Ahmed Alfi

10th April, 2023
*/ 

#include "tools.hpp"
#include "clist.hpp"
#include "player.hpp"

//---------------------------main()
int main() { 
    banner();

    CList plist;

    plist.init();
    cout <<"Players: " <<plist.count() <<endl;
    cout <<"----------------Adding 4 players" <<endl;
    plist.addCell(new Player("John", ECcolor::blue));
    plist.addCell(new Player("Alice", ECcolor::green));
    plist.addCell(new Player("Ifti", ECcolor::orange));
    plist.addCell(new Player("Jacob", ECcolor::yellow));
    cout <<plist;
    cout <<"Players: " <<plist.count() <<endl;
    
    cout <<"----------------Removing all players" <<endl;
    int pCount = plist.count();
    for (int m=0; m<pCount; m++) {
        plist.remove();
        cout <<"----------------remove() called " <<m+1 <<endl;
        cout <<plist;
        cout <<"Players: " <<plist.count() <<endl;
    }
    
    cout <<"----------------Adding players again" <<endl;
    plist.addCell(new Player("Ifti", ECcolor::orange));
    plist.addCell(new Player("Jacob", ECcolor::yellow));
    plist.addCell(new Player("John", ECcolor::blue));
    cout <<plist;
    cout <<"Players: " <<plist.count() <<endl;
    
    for (int m=0; m<5; m++) {
        cout <<"----------------Calling next() function" <<endl;
        plist.next();
        Player currentPlayer = plist.getCurrentPlayer();
        cout <<"Current player: " <<currentPlayer <<endl;
    }
    
    bye();
}