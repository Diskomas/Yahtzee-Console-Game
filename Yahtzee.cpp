#include "Yahtzee.h"
#include <iostream>
#include "Database.h"
#include <vector>
#include <charconv>
#include <algorithm>
#include <numeric>
#include <fstream>  

using namespace std;

Yahtzee::Yahtzee() {
    fill_n(ScoreCard, 6, 0);
    Game_Rolls = 0;
    Dice_Rolls = 0;
}

Yahtzee::~Yahtzee() {

}


void Yahtzee::Play() {
    while (Game_Rolls < 6){
        Game_Rolls++;
        for (int i = 0; i < 3; i++) {
            Dice_Rolls++;
            Roll_Dices(true); // Roll dices for the game
            Display_Game(); // Display current game data
            Lock_Dice();// lock dices
        }
        Dice_Rolls = 0; // Reset rolls (new round)
        fill_n(Dices[1], 5, 0); // Unselect all cards
        Score_Dice(); // save curent game score

        Save_Draft(); // save a draft of the game
    }

    Game_Rolls = 0; // reset rolls (for next game)
    Delete_draft(); // remove draft 
    // save game
    

}

void Yahtzee::Delete_draft(){
    remove("C:\\Users\\disko\\OneDrive\\Documents\\1. Sheffiled Hallam University\\Year 2\\ADVANCED PROGRAMMING\\Assessment\\Application\\Yahtzee_Game\\Database\\Drafts\\Draft_USERID.txt");
}

void Yahtzee::Save_Draft() {
    ofstream outfile("C:\\Users\\disko\\OneDrive\\Documents\\1. Sheffiled Hallam University\\Year 2\\ADVANCED PROGRAMMING\\Assessment\\Application\\Yahtzee_Game\\Database\\Drafts\\Draft_USERID.txt");
    // Roll Set, Aces, Twos, Threes, Fours, Fives, Sixes
    outfile << Game_Rolls << "," << ScoreCard[0] << "," << ScoreCard[1] << "," << ScoreCard[2] << "," << ScoreCard[3] << "," << ScoreCard[4] << "," << ScoreCard[5] << "," << endl;
    outfile.close();
}

void Yahtzee::Score_Dice() {
    int ScoreAgainst;
    cout << "\n\tEnter number to score against: ";
    cin >> ScoreAgainst;
    if (ScoreCard[ScoreAgainst - 1] != 0) {
        ScoreCard[ScoreAgainst - 1] = 0;
    }
    for (int i = 0; i < 5; i++) {
        
        if (Dices[0][i] == ScoreAgainst) {
            ScoreCard[ScoreAgainst-1] += ScoreAgainst;
        }
    }
}

void Yahtzee::Lock_Dice() {
    int DiceNumber = 999;
    while (DiceNumber != 0) {
        cout << "\n\tEnter dice number to lock/unlock (0 to continue): ";
        cin >> DiceNumber;
        if (Dices[1][DiceNumber - 1] != 1 && DiceNumber != 0 && DiceNumber < 6) {
            Dices[1][DiceNumber - 1] = 1;
        }
        else if(DiceNumber != 0 && DiceNumber < 6){
            Dices[1][DiceNumber - 1] = 0;
        }
        Display_Game();
    }
}

void Yahtzee::Roll_Dices(bool ForGame) {
    for (int i = 0; i < 5; i++) {
        if (Dices[1][i] != 1) {
            if (ForGame) {
                Dices[0][i] = rand() % 6 + 1;
            }
            else {
                SetCardFaces(CardFaces, Dices[0][i], false);
            }
        }
        else {
            if (!ForGame) {
                SetCardFaces(CardFaces, Dices[0][i], true);
            }
        }
    }
}

void Yahtzee::Display_Game() {
    cout << "\n\t\t\t\t       o8=======================8o" << endl;
    cout << "\t\t\t\t         |Dice Roll Set #" << Game_Rolls << " of " << 6 << "|\n";
    cout << "\t\t\t\t       o8=======================8o" << endl;

    cout << "\n\t\t\t\t                 o--o0o--o              " << endl;
    cout << "\t\t\t\t   8=8==========SCORECARD==========8=8" << endl;
    cout << "\t\t\t\t    |  NAME                  SCORE  | " << endl;
    cout << "\t\t\t\t    |                               | " << endl;
    cout << "\t\t\t\t    |  Aces:                  "<< ScoreCard[0] <<"     | " << endl;
    cout << "\t\t\t\t    |  Twos:                  "<< ScoreCard[1] <<"     | " << endl;
    cout << "\t\t\t\t    |  Threes:                "<< ScoreCard[2] <<"     | " << endl;
    cout << "\t\t\t\t    |  Fours:                 "<< ScoreCard[3] <<"     | " << endl;
    cout << "\t\t\t\t    |  Fives:                 "<< ScoreCard[4] <<"     | " << endl;
    cout << "\t\t\t\t    |  Sixes:                 "<< ScoreCard[5] <<"     | " << endl;
    cout << "\t\t\t\t    |                               | " << endl;
    cout << "\t\t\t\t   8=8==========SCORECARD==========8=8" << "\n\n";

    int Total = 0; 

    cout << "\t\t         o8===================8o" << "\t o8===============8o" << endl;
    cout << "\t\t           |    Total: " << accumulate(ScoreCard, ScoreCard + 6, Total) << "     |" << "\t\t   |   Roll #" << Dice_Rolls << "   |" << endl;
    cout << "\t\t         o8===================8o" << "\t o8===============8o" << endl;

    Roll_Dices(false);
    cout << "\n\n\t\t" << CardFaces[0] << "\n";
    cout << "\t\t" << CardFaces[1] << "\n";
    cout << "\t\t" << CardFaces[2] << "\n";
    cout << "\t\t" << CardFaces[3] << "\n";
    cout << "\t\t" << CardFaces[4] << "\n";

    fill_n(CardFaces, 5, "");
}

void Yahtzee::SetCardFaces(string(&Cards)[5], int RolledNumber, bool Occupation) {
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

