#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Database
{
public:
	Database(string path, string filename);
	~Database();

	// attempt 1:
	void Read(vector<string>* data);
	//bool MemberLogin(int* sessionID, string Username, string Password);
	// attempt 2:
	void Members(vector<string>* data);
	bool MemberLogin(string* Users, int* SessionID, string Username, string Password);
	string Write();

private:
	string path, filename;
};

