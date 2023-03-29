/*
Program 6 - One Turn
Iftiaz Ahmed Alfi

29th March, 2023
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