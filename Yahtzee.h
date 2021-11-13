#pragma once
#include <iostream>
#include "Database.h"
#include "Yahtzee.h"
#include <vector>
#include <charconv>
#include <algorithm>
#include <numeric>
using namespace std;

class Yahtzee
{
public:
	Yahtzee();
	~Yahtzee();

	void Play();
	void Roll_Dices(bool ForGame); // set or roll dices for display
	void Lock_Dice();
	void Score_Dice();

	void Save_Draft();
	void Delete_draft();

	void Display_Game(); // Display up to date game screen
	void Display_End();
	static void SetCardFaces(string(&Cards)[5], int RolledNumber, bool Occupation); // write cards for display


private:
	int Game_Rolls, Dice_Rolls, ScoreCard[6], Dices[2][5];
	string CardFaces[5];
};

