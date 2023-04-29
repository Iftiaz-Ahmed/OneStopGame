/*
Program 10 - Exception
Iftiaz Ahmed Alfi

29th April, 2023
*/ 

#pragma once
#include "tools.hpp"

class BadChoice {
public:
    char* choice;
    BadChoice(char* c) : choice(c) {};
    virtual ~BadChoice()=default;
    virtual void print() {
        cerr <<" Bad choice has been made.\n"
        << " Choose whether to ROLL, STOP or QUIT\n";
    }
    void pr() {
        cerr <<" You entered " <<choice
        <<". Please reenter.\n";
    }
};

class DuplicateSlot : public BadChoice {
public:
    DuplicateSlot(char* c) : BadChoice(c) {};
    virtual ~DuplicateSlot() {};
    virtual void print() {
        cerr <<" Two slots cannot be same\n";
        pr();
    }
};

class BadSlot : public BadChoice {
public:
    BadSlot(char* c) : BadChoice(c) {};
    virtual ~BadSlot() {};
    virtual void print() {
        cerr <<" Legal slots are a, b, c and d\n";
        pr();
    }
};