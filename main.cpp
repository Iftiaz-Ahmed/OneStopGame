/*
Program 7 - Player List
Iftiaz Ahmed Alfi

10th April, 2023
*/ 

#include "tools.hpp"
#include "clist.hpp"
#include "player.hpp"
#include "game.hpp"

//---------------------------main()
int main() { 
    banner();

    CList<Player*> plist;
    plist.init();
    cout <<"----------------Players: " <<plist.count() <<endl;
    cout <<"----------------Creating two dummy players" <<endl;
    plist.addCell(new Player("Alice", ECcolor::blue));
    plist.addCell(new Player("Ifti", ECcolor::orange));
    cout <<plist;
    cout <<"----------------Players: " <<plist.count() <<endl;
    
    cout <<"----------------Removing all players" <<endl;
    int pCount = plist.count();
    for (int m=0; m<pCount; m++) {
        plist.remove();
        cout <<"----------------remove() called " <<m+1 <<endl;
        cout <<plist;
        cout <<"----------------Players: " <<plist.count() <<endl;
    }
    
    cout <<"----------------Adding players again" <<endl;
    plist.addCell(new Player("Alice", ECcolor::blue));
    plist.addCell(new Player("Ifti", ECcolor::orange));
    cout <<plist;
    cout <<"----------------Players: " <<plist.count() <<endl;
    
    for (int m=0; m<5; m++) {
        cout <<"----------------Calling next() function" <<endl;
        plist.next();
        Player* currentPlayer = plist.getItem();
        cout <<"Current player: " <<*currentPlayer <<endl;
    }
    
    bye();
}