/*
Program 11 - A Whole Game
Iftiaz Ahmed Alfi

3rd May, 2023
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

bool Game:://------------------------------checkData()
checkData(char* name, char* color) {
    toLowerCase(color);
    try {
        for (int m=0; m<playerList.count(); m++) {
            Player* player = playerList.getItem();
            if (name == player->getName()) 
                throw BadName(name, color);
            else if (*player == color) 
                throw BadColor(name, color);
            playerList.next(); 
        }
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
    char name[50];
    char color[50];
    for (;;) {
        cout << "Enter player information: " << endl; 
        cout << "Name: ";  cin >> name;
        cout << "Color: "; cin >> color;
        cout << endl;
        if (checkData(name, color)) break;
    }
    return new Player(name, convertColor(color));
}

void Game:: //-----------------setPlayers()
setPlayers() {
    int n = 0;
    for (;;) {
        cout <<"Enter the number of players: ";
        cin >> n;
        if (n<2 || n>4) cout <<"Player no. can't be less than 2 or more than 4" <<endl;
        else break;
    }

    for (int m=0; m<n; m++) {
        cout <<"Player: " <<m+1 <<endl;
        playerList.addCell(getNewPlayer());
    }
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
                dicePairs = diceSet->roll();
                if (rollDice(gameBoard, dicePairs)) break;
            } else if (menuSelected == 2) {
                gameBoard.stop();
                if (pp->getScore() == 3) gameState = GameState::done;
                break;
            } else if (menuSelected == 3) {
                cout <<pp->getName() <<" resigned!" <<endl;
                gameBoard.bust(); 
                playerList.remove();
                if (playerList.count() < 1) gameState = GameState::quit;
                break; 
            } else throw BadChoice(menuSelected);
        } catch (BadChoice& bc) { bc.print(); }   
        catch (...) { fatal("Unknown error occurred!"); }
    }
}

void Game:: //-------------------play()
play() {
    playerList.init();
    for (;;) {
        if (gameState != GameState::begun || playerList.empty()) break;
        Player* const pp = playerList.getItem();
        oneTurn(pp);
        cout <<"\n" <<gameBoard;
        playerList.next();
        if (gameState == GameState::done) {
            cout <<pp->getName() <<" won the game" <<endl;
            break;
        }
        else if (gameState == GameState::quit) break;
    }
}