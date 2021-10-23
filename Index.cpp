#include <iostream>
using namespace std;
#include <iostream>
#include "Database.h"
#include <vector>
#include <charconv>
#include <algorithm>


static void Yahtzee_Menu(), MemberLogin(), Game(), MemberMenu();
int* SessionID; // for sessionID

int main() {
    //  APPLICAITON CONFIG

    srand(time(NULL));

    //  APPLICAITON CONFIG

    int Menu_Selection;
    do {
        Yahtzee_Menu();
        cout << "\n   Please enter your selection: "; cin >> Menu_Selection;

        switch (Menu_Selection)
        {
        case 1:
            if (SessionID != nullptr) {MemberMenu();}
            else {MemberLogin();}
            if (SessionID != nullptr) { MemberMenu(); }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 9:
            break;
        default:
            break;
        }


    } while (Menu_Selection != 9);

    free(SessionID);
    return 0;

    /* OPTION 1 
    
    USE ARRAYS AND MALLOC THE SIZE NEEDED IN THAT PARTICULAR TIME
        
            int counter = 1;
    string temp;
                if (counter < 2) {
            temp = data;
        }
        else {
            cout << temp << "\t" << data <<endl;
            counter = 0;
        }
        counter++;
    for (auto data : *scoreData) {
        
   
        cout << data << "\t\t";
        //string* data = new string[5];
    //auto topGames = new string[5][2];
    }
    */
}

static void Yahtzee_Menu() {
    cout << "   o8=============================================================================================8o" << endl;
    cout << "\t        __  __     ______     __  __     ______   ______     ______     ______    " << endl;
    cout << "\t       /\\ \\_\\ \\   /\\  __ \\   /\\ \\_\\ \\   /\\__  _\\ /\\___  \\   /\\  ___\\   /\\  ___\\   " << endl;
    cout << "\t       \\ \\____ \\  \\ \\  __ \\  \\ \\  __ \\  \\/_/\\ \\/ \\/_/  /__  \\ \\  __\\   \\ \\  __\\   " << endl;
    cout << "\t        \\/\\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\    \\ \\_\\   /\\_____\\  \\ \\_____\\  \\ \\_____\\ " << endl;
    cout << "\t         \\/_____/   \\/_/\\/_/   \\/_/\\/_/     \\/_/   \\/_____/   \\/_____/   \\/_____/ " << endl;
    cout << "\n\n       By: Mantas Tamasauskas          Student ID: 30029478\n   o8=============================================================================================8o" << endl;

    vector<string>* scoreData = new vector<string>;
    Database* TopScore = new Database("", "TopGames.txt");

    TopScore->Read(scoreData);
    delete TopScore;
    cout << "\t\t\t\t                 o--o0o--o              " << endl;
    cout << "\t\t\t\t   8=8==========LEADERBOARD==========8=8" << endl;
    cout << "\t\t\t\t    |  NAME                    SCORE  | " << endl;
    cout << "\t\t\t\t    |                                 | " << endl;
    for (int i = 0; i < scoreData->size(); i += 2) {
        int inicialPosition = 20 - size(scoreData->at(i));

        cout << "\t\t\t\t    | " << scoreData->at(i);

        for (int x = 0; x <= (26 - size(scoreData->at(i)) ); x++) { cout << " ";}
        
        cout << scoreData->at(i + 1) << "   | " << endl;
    }
    cout << "\t\t\t\t    |                                 | " << endl;
    cout << "\t\t\t\t   8=8==========LEADERBOARD==========8=8" << "\n\n";
    delete(scoreData);
    scoreData= nullptr;

    cout << "   o8========8o    o8============8o    o8=================8o    o8================8o     o8========8o" << endl;
    cout << " (1) | PLAY |    (2) | REGISTER |    (3) | DELETE PLAYER |    (4) | SORT PLAYERS |     (9) | EXIT |  " << endl;
    cout << "   o8========8o    o8============8o    o8=================8o    o8================8o     o8========8o" << endl;

}

static void MemberLogin() {
    
    SessionID = (int*)malloc(sizeof(int) * 1);
    Database* MemberData = new Database("", "Members.txt");
    string Mem_Username, Mem_Password;

    cout << "\n\n Please Enter Login details: \n";
    cout << " ---------------------------\n\n";
    cout << " Username: ";
    cin >> Mem_Username; // needs fixing
    replace(Mem_Username.begin(), Mem_Username.end(), ' ', '*');
    cout << " Password: ";
    cin >> Mem_Password;

    if (MemberData->MemberLogin(SessionID, Mem_Username, Mem_Password)) {
        cout << "Logged in! " << endl;
    }
    else {
        free(SessionID);
        SessionID = nullptr;
    }
    delete MemberData;
}

static void MemberMenu() {
    cout << "   o8===================================8o" << endl;
    cout << "               Welcome {USERNAME}" << endl;
    cout << "   o8===================================8o" << "\n\n";

    cout << "                  o--o0o--o              " << endl;
    cout << "    8=8==========SCOREBOARD==========8=8" << endl;
    cout << "     |  TYPE                   SCORE  | " << endl;
    cout << "     |                                | " << endl;
    cout << "     |  Highest                  X    | " << endl;
    cout << "     |  Accumulated              X    | " << endl;
    cout << "     |  Average                  X    | " << endl;
    cout << "     |                                | " << endl;
    cout << "    8=8=========GAMES PLAYED=========8=8" << endl;
    cout << "     |  Total                    X    | " << endl;
    cout << "    8=8==============================8=8" << "\n\n";

    cout << "                o8========8o  " << endl;
    cout << "              (1) | PLAY |    " << endl;
    cout << "                o8========8o  " << "\n\n";
    cout << "           o8==================8o  " << endl;
    cout << "         (2) | GAMES  HISTORY |    " << endl;
    cout << "           o8==================8o  " << "\n\n";
    cout << "                o8========8o  " << endl;
    cout << "              (9) | BACK |    " << endl;
    cout << "                o8========8o  " << "\n\n";
    int Menu_Selection;
    cout << "\n   Please enter your selection: "; cin >> Menu_Selection;
}

static void Game() {

    int Difficulty = 6; // dice rolls

   // int SCORECARD[Difficulty];

    for (int x = 0; x < Difficulty; x++) {
        cout << " Dice Roll Set #"<< (x + 1) <<" of "<< Difficulty <<"\n";
        cout << "-------------------\n\n";
        cout << "--- SCORECARD ---\n";




        int Dices[2][5];

        for (int rolls = 0; rolls < 3; rolls++) {

            for (int i = 0; i < 5; i++) {
                if (Dices[1][i] != 1) {
                    Dices[0][i] = rand() % 6 + 1;
                }

                // print the dices 

                // ask for locking any dices
                // example :
                Dices[1][1] = 1; // means its locked and will not be remplaced

            }
        }

        // select to store against something
        // continue with the next round
    }
}
