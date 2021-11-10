#include <iostream>
using namespace std;
#include <iostream>
#include "Database.h"
#include <vector>
#include <charconv>
#include <algorithm>
#include <numeric>


static void Yahtzee_Menu(), MemberLogin(), Game(), MemberMenu(), Yahtzee_Menu2(), SimpleCard(string(&Cards)[5], int RolledNumber, bool Occupation);
int* SessionID; // for sessionID
string* Members; // cstring 


int main() {
    // TESTING

    

    // TESTING




    //  APPLICAITON CONFIG

    srand(time(NULL));

    //  APPLICAITON CONFIG

    int Menu_Selection;
    do {
        //Yahtzee_Menu();
        Yahtzee_Menu2();
        cout << "\n   Please enter your selection: "; cin >> Menu_Selection;

        switch (Menu_Selection)
        {
        case 1:
            Game();
            break;
            // testing
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

static void Yahtzee_Menu2() {
    cout << "   o8=============================================================================================8o" << endl;
    cout << "\t        __  __     ______     __  __     ______   ______     ______     ______    " << endl;
    cout << "\t       /\\ \\_\\ \\   /\\  __ \\   /\\ \\_\\ \\   /\\__  _\\ /\\___  \\   /\\  ___\\   /\\  ___\\   " << endl;
    cout << "\t       \\ \\____ \\  \\ \\  __ \\  \\ \\  __ \\  \\/_/\\ \\/ \\/_/  /__  \\ \\  __\\   \\ \\  __\\   " << endl;
    cout << "\t        \\/\\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\    \\ \\_\\   /\\_____\\  \\ \\_____\\  \\ \\_____\\ " << endl;
    cout << "\t         \\/_____/   \\/_/\\/_/   \\/_/\\/_/     \\/_/   \\/_____/   \\/_____/   \\/_____/ " << endl;
    cout << "\n\n       By: Mantas Tamasauskas          Student ID: 30029478\n   o8=============================================================================================8o" << endl;

    vector<string>* MembersData = new vector<string>;
    Database* MemberData = new Database("", "Members_v2.txt");

    MemberData->Members(MembersData);
    delete MemberData;

    //const int ArraySize = MembersData->size() - 1;
    //string* UserData = new string[2][2];// = new char[MembersData->size() - 1];

    //string** arr= new string * [MembersData->size() - 1];
    //char* y = new char[5][2];

    //const int size = const_cast<const int&>(MembersData->size());
    //string* str[size][5];

    int ArraySize = MembersData->size() - 1, x = 0;
    Members = new string[ArraySize * 3]; // C-STRING as requested by the brief   // USE CHAR!!!!!!!!!!!!!!!
  


    cout << "\t\t\t\t                 o--o0o--o              " << endl;
    cout << "\t\t\t\t   8=8==========LEADERBOARD==========8=8" << endl;
    cout << "\t\t\t\t    |  NAME                    SCORE  | " << endl;
    cout << "\t\t\t\t    |                                 | " << endl;
    for (int i = 0; i < ArraySize; i += 4) {
        *(Members + x * 3 + 0) = MembersData->at(i); // memberID
        *(Members + x * 3 + 1) = MembersData->at(i + 1); // Username
        string MemberPassword = MembersData->at(i + 2);

        for (int i = 0; (i < 20 && MemberPassword[i] != '\0'); i++) // password decryption
            MemberPassword[i] = MemberPassword[i] - 3;

        *(Members + x * 3 + 2) = MemberPassword;
        x++;

        int inicialPosition = 26 - size(MembersData->at(i + 1)); // calculate number of spaces needed

        cout << "\t\t\t\t    | " << MembersData->at(i + 1); // display username

        for (int x = 0; x <= inicialPosition; x++) { cout << " "; } // disoplay spaces

        cout << MembersData->at(i + 3) << "   | " << endl; // display score !can be imroved here!
    }
    cout << "\t\t\t\t    |                                 | " << endl;
    cout << "\t\t\t\t   8=8==========LEADERBOARD==========8=8" << "\n\n";

    delete(MembersData);
    MembersData = nullptr;

    cout << "   o8========8o    o8============8o    o8=================8o    o8================8o     o8========8o" << endl;
    cout << " (1) | PLAY |    (2) | REGISTER |    (3) | DELETE PLAYER |    (4) | SORT PLAYERS |     (9) | EXIT |  " << endl;
    cout << "   o8========8o    o8============8o    o8=================8o    o8================8o     o8========8o" << endl;
    // USE C-STRING "Members" TO FUTHER TAKE THE APPLICATION (TO LOGIN / DELETE / SORT PLAYERS)
}

static void MemberLogin() {

    SessionID = (int*)malloc(sizeof(int) * 1);



    /*
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
    */
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

    const int Difficulty = 6; // dice rolls

    int SCORECARD[Difficulty];

    for (int x = 0; x < Difficulty; x++) {
        cout << " Dice Roll Set #"<< (x + 1) <<" of "<< Difficulty <<"\n";
        cout << "-------------------\n\n";
        cout << "--- SCORECARD ---\n";

        cout << "\t Aces: " << SCORECARD[0] << "\n";
        cout << "\t Twos: " << SCORECARD[1] << "\n";
        cout << "\t Threes: " << SCORECARD[2] << "\n";
        cout << "\t Fours: " << SCORECARD[3] << "\n";
        cout << "\t Fives: " << SCORECARD[4] << "\n";
        cout << "\t Sixes: " << SCORECARD[5] << "\n";
        cout << "-----------------\n";
        int Total = 0;
        accumulate(SCORECARD, SCORECARD + Difficulty, Total);
        cout << "Total: " << Total << "\n";
        cout << "-----------------\n";

        int Dices[2][5];
        string CardFaces[5];

        for (int rolls = 0; rolls < 3; rolls++) {

            for (int i = 0; i < 5; i++) {
                if (Dices[1][i] != 1) {
                    Dices[0][i] = rand() % 6 + 1;
                    SimpleCard(CardFaces, Dices[0][i], false); // create a separate loop to only print dices 
                }
                else {
                    SimpleCard(CardFaces, Dices[0][i], true);
                }
            }

            cout << "Roll #" << rolls + 1 << "\n";

            cout << CardFaces[0] << "\n";
            cout << CardFaces[1] << "\n";
            cout << CardFaces[2] << "\n";
            cout << CardFaces[3] << "\n";
            cout << CardFaces[4] << "\n";

            fill_n(CardFaces, 5, "");
            int LockSelection;

            cout << "\n\n Enter card to lock or skip(0): ";
            cin >> LockSelection;
            while (LockSelection != 0) {
                Dices[1][LockSelection-1] = 1;
                cin >> LockSelection;
            }


        }

        cout << "";
    }
}

static void SimpleCard(string (&Cards)[5], int RolledNumber, bool Occupation) {
    if (Occupation) {
        Cards[0].append("o8=====8o\t");
        Cards[4].append("o8=====8o\t");
    }
    else {
        Cards[0].append(".-------.\t");
        Cards[4].append("'-------'\t");
    }
    switch (RolledNumber)
    {
        
    case 1:
        Cards[1].append("|       |\t");
        Cards[2].append("|   *   |\t");
        Cards[3].append("|       |\t");
        break;
    case 2:
        Cards[1].append("| *     |\t");
        Cards[2].append("|       |\t");
        Cards[3].append("|     * |\t");
        break;
    case 3:
        Cards[1].append("| *     |\t");
        Cards[2].append("|   *   |\t");
        Cards[3].append("|     * |\t");
        break;
    case 4:
        Cards[1].append("| *   * |\t");
        Cards[2].append("|       |\t");
        Cards[3].append("| *   * |\t");
        break;
    case 5:
        Cards[1].append("| *   * |\t");
        Cards[2].append("|   *   |\t");
        Cards[3].append("| *   * |\t");
        break;
    case 6:
        Cards[1].append("| *   * |\t");
        Cards[2].append("| *   * |\t");
        Cards[3].append("| *   * |\t");
        break;
    default:
        break;
    }
}
