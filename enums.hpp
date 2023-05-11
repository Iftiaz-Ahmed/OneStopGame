/*
Program 13
Iftiaz Ahmed Alfi

11th May, 2023
*/ 

#ifndef ENUMS_HPP
#define ENUMS_HPP
#include "tools.hpp"

enum class ColumnState {available, pending, captured};
enum class ECcolor {white, orange, yellow, green, blue};
enum class GameState {begun, done, quit};

extern const char* cState[];
extern const char* words[];
extern const char* symbols[];

#endif