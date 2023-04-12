/*
Program 7 - Player List
Iftiaz Ahmed Alfi

10th April, 2023
*/ 

#include "game.hpp" 

//------------------------------toLowerCase()
string toLowerCase(string &str) {
    string result;
    for (char c : str) result += tolower(c);

    return result;
}

//------------------------------validateColor()
ECcolor validateColor(bool* colorsUsed) {
    string color;
    ECcolor acceptedColor;
    map<string, ECcolor> colorMap{
        {"white", ECcolor::white},
        {"orange", ECcolor::orange},
        {"yellow", ECcolor::yellow},
        {"green", ECcolor::green},
        {"blue", ECcolor::blue}};

    for(;;) {
        cout << "Color: ";
        cin >> color;
        string lowCaseColor = toLowerCase(color);
        int colorInList = colorMap.count(lowCaseColor);
        int index = (int)colorMap[lowCaseColor];

        if (colorInList > 0 && colorsUsed[index] == false) {
            colorsUsed[index] = true;
            acceptedColor = colorMap[lowCaseColor];
            break;
        }
        else cout <<color <<" not available. Try again!" << endl;
    }
    return acceptedColor;
}

Player* Game:: //-----------------getNewPlayer()
getNewPlayer() {
    string name;
    ECcolor color;
 
    cout << "Enter player information: " << endl; 
    cout << "Name: ";
    cin >> name;
    color = validateColor(colorsUsed);
    cout << endl;

    return new Player(name, color);
}

int menu() { //-------------------menu()
    int x;

    for(;;) {
        cout <<"\nType:\n1 - Roll Dice\n2 - Stop\n3 - Resign\n: ";
        cin >> x;
        if (x > 0 && x < 4) break;
        else cout <<"Wrong input. Try again!" <<endl;
    }
    return x;
}

char validSelection() { //-------------validSelection()
    char selected;
    for(;;) {
        cout <<": ";
        cin>> selected;
        selected = tolower(selected);
        if (selected == 'f' || selected == 's') break;
        else cout <<"Wrong input. Try again!" <<endl;
    }
    return selected;    
}

bool rollDice(Board& gameBoard, Dice* diceSet) {
    diceSet->roll();
    diceSet->print(cout);
    diceSet->makePair();
    array<int, 2> pairs = diceSet->getPairSums();
    
    int failedMove = 0;
    for(const auto& m : pairs)
        if (gameBoard.move( m) == false)
            failedMove++;
    
    if (failedMove == 2) {
        gameBoard.bust();
        return true;
    }
    cout <<gameBoard;
    return false;
}

void Game:: //-------------------oneTurn()
oneTurn(Player* pp) {
    gameBoard.startTurn(pp); 
    for(;;) {
        int menuSelected = menu();
        if (menuSelected == 1) { 
            if (rollDice(gameBoard, diceSet)) break;
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
    oneTurn(player);

    cout <<"\n--------------------Final result:" <<endl;
    cout <<player;
    cout <<gameBoard;
}