/*
Program 4 - Game
Iftiaz Ahmed Alfi and Anwar Haq

22nd Feb, 2023
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