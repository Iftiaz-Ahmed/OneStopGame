/*
Program 5 - Board
Iftiaz Ahmed Alfi and Anwar Haq

18th March, 2023
*/ 

#include "game.hpp" 

//------------------------------toLowerCase()
string toLowerCase(string &str) {
    string result;
    for (char c : str)
    {
        result += tolower(c);
    }
    return result;
}

//------------------------------validateColor()
ECcolor validateColor(int* colorsUsed) {
    string color;
    ECcolor acceptedColor;
    map<string, ECcolor> colorMap{
        {"white", ECcolor::white},
        {"orange", ECcolor::orange},
        {"yellow", ECcolor::yellow},
        {"green", ECcolor::green},
        {"blue", ECcolor::blue}};

    while (true) {
        cout << "Color: ";
        cin >> color;
        string lowCaseColor = toLowerCase(color);
        int colorInList = colorMap.count(lowCaseColor);
        int index = (int)colorMap[lowCaseColor];

        if (colorInList > 0 && colorsUsed[index] == 0) {
            colorsUsed[index] = 1;
            acceptedColor = colorMap[lowCaseColor];
            break;
        }
        else cout <<color <<" not available. Try again!" << endl;
   
    }
    return acceptedColor;
}

Player Game:: //-----------------getNewPlayer()
getNewPlayer() {
    string name;
    ECcolor color;
 
    cout << "Enter player information: " << endl; 
    cout << "Name: ";
    cin >> name;
    color = validateColor(colorsUsed);
    cout << endl;

    return Player(name, color);
}

void Game:: //-------------------playGame()
playGame() {
    cout << gameBoard <<endl;

    gameBoard.startTurn(&player);
    gameBoard.move(3);
    gameBoard.move(9);
    gameBoard.move(2);
    gameBoard.stop();

    gameBoard.startTurn(&player);
    gameBoard.move(2);
    gameBoard.move(5);
    gameBoard.move(4);
    gameBoard.stop();

    gameBoard.startTurn(&player);
    gameBoard.move(2);
    gameBoard.move(5);
    gameBoard.move(4);
    gameBoard.stop();

    cout << player;
    cout <<gameBoard;
}