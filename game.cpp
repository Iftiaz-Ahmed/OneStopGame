/*
Program 4 - Game
Iftiaz Ahmed Alfi and Anwar Haq

22nd Feb, 2023
Resubmitted: 15th March, 2023
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
    //---------------------------Point 1 & 2
    cout <<"---------------------DiceSet" <<endl;
    diceSet->roll();
    diceSet->print(cout);

    cout <<"---------------------Player Info" <<endl;
    cout << player1;
    cout << player2;

    //------------------------------Point 3
    cout <<"---------------------Column7 startTower()" <<endl;
    column7.startTower(&player1);
    column7.move();
    cout << column7 << endl;

    //------------------------------Point 4
    cout <<"---------------------Column2 startTower()" <<endl;
    column2.startTower(&player2);
    column2.move();
    cout << column2 << endl;
    column2.move();
    column2.move();
    cout <<"---------------------Column2 after 3 move()" <<endl;
    cout << column2 << endl;

    column7.stop(&player1);
    column2.stop(&player2);
    cout <<"---------------------Column2 & 7 after stop()" <<endl;
    cout << column7 << endl;
    cout << column2 << endl;

    cout <<"---------------------Player Info after capture" <<endl;
    cout << player1;
    cout << player2;
}