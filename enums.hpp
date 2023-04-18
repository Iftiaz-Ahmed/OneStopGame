/*
Program 9 - Polymorphic Dice
Iftiaz Ahmed Alfi

17th April, 2023
*/ 

#ifndef ENUMS_HPP
#define ENUMS_HPP
#include "tools.hpp"

enum class ColumnState {available, pending, captured};
enum class ECcolor {white, orange, yellow, green, blue};

extern const char* cState[];
extern const char* words[];
extern const char* symbols[];

#endif