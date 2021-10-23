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

	void Read(vector<string>* data);
	bool MemberLogin(int* sessionID, string Username, string Password);
	string Write();

private:
	string path, filename;
};

