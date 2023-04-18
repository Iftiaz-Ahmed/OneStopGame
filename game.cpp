/*
Program 9 - Polymorphic Dice
Iftiaz Ahmed Alfi

17th April, 2023
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

//-------------------------------------------rollDice()
bool rollDice(Board& gameBoard, const int* pairs) {
    int failedMove = 0;
    for(int m=0; m<2; m++)
        if (gameBoard.move( pairs[m]) == false)
            failedMove++;
    
    if (failedMove == 2) {
        gameBoard.bust();
        return true;
    }
    cout <<gameBoard;
    return false;
}

void Game:: //-------------------------oneTurn()
oneTurn(Player* pp) {
    cout <<"\n" <<*pp;
    gameBoard.startTurn(pp); 
    for(;;) {
        int menuSelected = menu();
        if (menuSelected == 1) { 
            if (rollDice(gameBoard, diceSet->roll())) break;
        } else if (menuSelected == 2) {
            gameBoard.stop();
            cout <<gameBoard;
            break;
        } else if (menuSelected == 3) { break; }
    }  
}

void Game:: //-------------------playGame()
playGame() {
    cout <<"\n---------CantStopDice Testing Start" <<endl;
    playerList.init();
    oneTurn(playerList.getItem());
    cout <<"\n---------Final result (CantStopDice Class):" <<endl;
    cout <<*playerList.getItem();
    cout <<gameBoard;
    cout <<"\n---------CantStopDice Testing End" <<endl;

    cout <<"\n---------FakeDice Testing Start" <<endl;
    diceSet = new FakeDice();
    gameBoard.clearBoard();
    playerList.init();
    for(;;) {
        oneTurn(playerList.getItem());
        if (playerList.getItem()->getScore() == 3) {
             cout <<"\n!!! WIN !!!\n" <<*playerList.getItem();
             break;
        }
        playerList.next();
    }
    cout <<"\n---------FakeDice Testing End" <<endl;
}