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
/*
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
*/




void Database::Members(vector<string>* data) {

	string Record;
	ifstream Data(this->path + this->filename);

	if (Data.is_open()) {
		while (getline(Data, Record, ',')) { // read csv files
			Record.erase(remove(Record.begin(), Record.end(), '\n'), Record.end());
			replace(Record.begin(), Record.end(), '*', ' '); //special way of assigning spaces in records
			data->push_back(Record); // push data on vector
		}
	}
	else {
		cout << "Fail to read database table" << endl;
	}
	Data.close();
}
	

bool Database::MemberLogin(string* Users, int* SessionID, string Username, string Password) {
	int i = 0;
	while (!Users[i].empty()) {
		
		if (Username == *(Users + i * 3 + 1) && Password == *(Users + i * 3 + 2)) {
			string SessionID = *(Users + i * 3 + 0);
			SessionID[0] = stoi(SessionID);
			return true;
		}
		i++;
	}
	cout << "Records not found in the database!";
	return false;
}

	string Database::Write() {
		return "";
	}

/*
ENCRYPTION

for(i = 0; (i < 100 && str[i] != '\0'); i++)
			str[i] = str[i] + 3;


*/