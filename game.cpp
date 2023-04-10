/*
Program 7 - Player List
Iftiaz Ahmed Alfi

10th April, 2023
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

int menu() { //-------------------menu()
    int x;

    while(true) {
        cout <<"\nType:\n1 - Roll Dice\n2 - Stop\n3 - Resign\n: ";
        cin >> x;
        if (x > 0 && x < 4) break;
        else cout <<"Wrong input. Try again!" <<endl;
    }
    return x;
}

char validSelection() { //-------------validSelection()
    char selected;
    while(true) {
        cout <<": ";
        cin>> selected;
        selected = tolower(selected);
        if (selected == 'a' || selected == 'b') break;
        else cout <<"Wrong input. Try again!" <<endl;
    }
    return selected;    
}

array<char, 2> choosePair(array<int, 2> pairs, 
map<char, int> options) { //------------choosePair()
    char selected;
    array<char, 2> pairOrder;
    
    cout <<"Select a pair to play: " <<endl;
    for(const auto& m : options) 
        cout <<m.first <<"->" <<pairs[m.second] <<" ";
    cout <<endl;
    selected = validSelection();

    if (selected == 'a') {pairOrder[0] = 'a'; pairOrder[1] = 'b';}
    else {pairOrder[0] = 'b'; pairOrder[1] = 'a';}
    return pairOrder;
}

void Game:: //-------------------oneTurn()
oneTurn(Player* pp) {
    array<char, 2> pairOrder;
    gameBoard.startTurn(pp); 
    while (true) {
        int menuSelected = menu();
        if (menuSelected == 1) { 
            diceSet->roll();
            diceSet->print(cout);
            diceSet->makePair();
            array<int, 2> pairs = diceSet->getPairSums();
            map<char, int> options = { {'a', 0}, {'b', 1} };
            pairOrder = choosePair(pairs, options);
            
            int failedMove = 0;
            for(const auto& m : pairOrder)
                if (gameBoard.move( pairs[options[m]]) == false)
                    failedMove++;
            
            if (failedMove == 2) {
                gameBoard.bust();
                break;
            }
            cout <<gameBoard;
        }
        else if (menuSelected == 2) {
            gameBoard.stop(); 
            cout <<gameBoard;
            break;
        } 
    }  
}

void Game:: //-------------------playGame()
playGame() {
    oneTurn(&player);

    cout <<"\n--------------------Final result:" <<endl;
    cout <<player;
    cout <<gameBoard;
}