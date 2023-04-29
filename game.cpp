/*
Program 10 - Exception
Iftiaz Ahmed Alfi

29th April, 2023
*/ 

#include "game.hpp" 
#include "badPlayer.hpp"
#include "badChoice.hpp"

//------------------------------toLowerCase()
void toLowerCase(char* str) {
    for (int m = 0; str[m] != '\0'; m++) str[m] = tolower(str[m]);
}

//------------------------------convertColor()
ECcolor convertColor(char* color) {
    map<string, ECcolor> colorMap{
        {"white", ECcolor::white},
        {"orange", ECcolor::orange},
        {"yellow", ECcolor::yellow},
        {"green", ECcolor::green},
        {"blue", ECcolor::blue}};

    toLowerCase(color);
    return colorMap[color];   
}

//------------------------------validateColor()
bool validateColor(char* color, bool* colorsUsed) {
    map<string, ECcolor> colorMap{
        {"white", ECcolor::white},
        {"orange", ECcolor::orange},
        {"yellow", ECcolor::yellow},
        {"green", ECcolor::green},
        {"blue", ECcolor::blue}};
    
    toLowerCase(color);
    int colorInList = colorMap.count(color);
    int index = (int)colorMap[color];

    if (colorInList > 0 && colorsUsed[index] == false) {
        colorsUsed[index] = true;
        return true;
    } else return false;
}

bool Game:://------------------------------checkData()
checkData(char* name, char* color) {
    try {
        for (int m=0; m<playerList.count(); m++) {
            Player* player = playerList.getItem();
            if (name == player->getName()) 
                throw BadName(name, color);
            playerList.next(); 
        }
        if (!validateColor(color, colorsUsed))
            throw BadColor(name, color);
        return true;
    } catch (BadPlayer& bp) { 
        bp.basePrint(); 
        return false;
    } catch (...) {
        fatal("Error: Unable to validate name and color. Aborting.");
        return false;
    }
}

Player* Game:: //-----------------getNewPlayer()
getNewPlayer() {
    char* name = new char[50];
    char* color = new char[50];
    for (;;) {
        cout << "Enter player information: " << endl; 
        cout <<"Name: ";  cin >> name;
        cout <<"Color: "; cin >> color;
        cout << endl;
        if (checkData(name, color)) break;
    }
    Player* player = new Player(name, convertColor(color));
    delete[] name; 
    delete[] color;
    return player;
}

int menu() { //-------------------menu()
    int x;
    cout <<"\nType:\n1 - Roll Dice\n2 - Stop\n3 - Resign\n: ";
    cin >> x;
    return x;
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
        try {
            int menuSelected = menu();
            if (menuSelected == 1) { 
                if (rollDice(gameBoard, diceSet->roll())) break;
            } else if (menuSelected == 2) {
                gameBoard.stop();
                cout <<gameBoard;
                break;
            } else if (menuSelected == 3) { break; }
            else throw BadChoice((char*) menuSelected);
        } 
        catch (BadChoice& bc) { bc.print(); }   
        catch (...) { fatal("Unknown error occurred!"); }
    }
}

void Game:: //-------------------playGame()
playGame() {
    cout <<"\n---------FakeDice Testing Start" <<endl;
    playerList.init();
    oneTurn(playerList.getItem());
    cout <<"\n---------Final result:" <<endl;
    cout <<*playerList.getItem();
    cout <<gameBoard;
    cout <<"\n---------FakeDice Testing End" <<endl;
}