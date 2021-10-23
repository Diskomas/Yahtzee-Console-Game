#include "Database.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;




Database::Database(string path, string filename) {
	this->path = path;
	this->filename = filename;
}
Database::~Database() {

}

void Database::Read(vector<string>* data) {

	string Record;
	ifstream Data(this->path + this->filename);

	if (Data.is_open()) {
		while (getline(Data, Record, ',')) {
			Record.erase(std::remove(Record.begin(), Record.end(), '\n'), Record.end());
			replace(Record.begin(), Record.end(), '*', ' ');
			data->push_back(Record);
		}
	}
	else {
		cout << "Fail to read database table" << endl;
	}
	Data.close();
}

bool Database::MemberLogin(int* sessionID,string Username, string Password) {
	string dbRecord, saveSession;
	ifstream Data(this->path + this->filename);

	bool username = false, password = false; int step = 0, IDcounter = 1;
	if (Data.is_open()) {
		while (getline(Data, dbRecord, ',')) {
			dbRecord.erase(std::remove(dbRecord.begin(), dbRecord.end(), '\n'), dbRecord.end());
			replace(dbRecord.begin(), dbRecord.end(), '*', ' ');

			if (IDcounter == 1) { saveSession = dbRecord; }
			else if (IDcounter == 3) { IDcounter = 0; }
			IDcounter++;

			if (dbRecord == Username) {username = true;}
			else if (username && dbRecord == Password) {password = true;}

			if (username && password && step < 2) {
				sessionID[0] = std::stoi(saveSession);
				Data.close();
				return true;
			}
			else if(username){step++;}
			if(step >= 2){
				cout << "Incorrect password";
				Data.close();
				return false;
			}
		}
	}
	else {
		cout << "Fail to read database table" << endl;
	}
	cout << "Record does not exist";
	Data.close();
	return false;
}

string Database::Write() {
	return "";
}


//string temp;
//if (counter < vectorSize) {
//	temp += myText;
//}
//else {
//
//	data->push_back(myText);
//}
//
//counter++;

//while (Data >> myName >> myText) {
//
//	replace(myName.begin(), myName.end(), '*', ' ');
//	cout << myName << "\t" << myText << endl;
//}

//if (tableSize == 2) {
			//	getline(Data, Text2);
			//	data[lineCounter] = { Text , Text2 };
			//}

			//lineCounter++;