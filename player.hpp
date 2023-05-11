/*
Program 13
Iftiaz Ahmed Alfi

11th May, 2023
*/ 

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "tools.hpp"
#include "enums.hpp"

class Player {
private:
    string name;
    ECcolor color;
    int score;
    int scoreboard[3];
public:
    //--------------------------Constuctors
    Player(string n, ECcolor c) : name(n), color(c), score(0) {}
    ~Player() = default;

    //--------------------------Prototypes
    ECcolor getColor() const { return color; };
    string getName() const { return name; };
    int getScore() const { return score; }; 
    bool wonColumn(int colNum);
    ostream& print(ostream& out);
    bool operator==(const string& c) const;
};

inline ostream& operator<< (ostream& out, Player& P) {
    return P.print( out );
}

inline bool Player::operator==(const string& c) const {
    map<string, ECcolor> colorMap{
        {"white", ECcolor::white},
        {"orange", ECcolor::orange},
        {"yellow", ECcolor::yellow},
        {"green", ECcolor::green},
        {"blue", ECcolor::blue}};

    if(color == colorMap[c] || colorMap[c] == ECcolor::white)
        return true;
    else return false;
}

#endif