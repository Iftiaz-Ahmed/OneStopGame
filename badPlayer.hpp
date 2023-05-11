/*
Program 13
Iftiaz Ahmed Alfi

11th May, 2023
*/ 

#pragma once
#include "tools.hpp"

class BadPlayer {
public:
    char* name;
    char* color;
    //-------------------Functions
    BadPlayer (char* n, char* c) : name(n), color(c) {};
    virtual ~BadPlayer() = default;
    virtual void basePrint() {
        cerr <<" Both name and color value are wrong\n"
        <<" Legal name values shouldn't start with number or symbols\n"
        <<" Legal color values are Orange, Yellow, Green and Blue\n"
        <<" Or " <<color <<" might be taken already\n";
        pr();
    }
    void pr() {
        cerr <<" You entered 'Name: " <<name <<" Color: " <<color
        << "'. Please reenter. \n\n";
    }
};

class BadName : public BadPlayer {
public:
    BadName (char* n, char* c) : BadPlayer(n, c) {};
    virtual ~BadName() {};
    virtual void basePrint() {
        cerr <<" Legal name should be unique."
        <<" Name already exists.\n";
        pr();
    }
};

class BadColor : public BadPlayer {
public:
    BadColor (char* n, char* c) : BadPlayer(n, c) {};
    virtual ~BadColor() {};
    virtual void basePrint() {
        cerr <<" Legal color values are Orange, Yellow, Green and Blue\n"
        <<" Or " <<color <<" might be taken already\n";
        pr();
    }
};