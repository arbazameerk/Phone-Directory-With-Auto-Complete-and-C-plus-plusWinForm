#pragma once
#include <vector>
#include <iostream>
#include "AVL.h"
#include "MyForm.h"
using namespace std;

class searcher:public AVL
{
public:
	vector<string> dict;
	void READ_SEARCHER()
	{
		string ph, name;//dummy variables
		ifstream read;
		read.open("DATA.csv", ios::in);
		string line;
		if (!read.is_open())
		{
			//cout << "\n\nCONTACTS FILE NOT FOUND\n\n";
		}
		while (getline(read, line))
		{
			stringstream ss(line);
			getline(ss, ph, ',');
			getline(ss, name, ',');
			dict.push_back(name);
		}
		read.close();
	}
	bool contains(string str1, string str2) 
	{
		//npos is constant static value with the highest possible value for an element
		return (str1.find(str2) != string::npos);
	}
	bool isNumber(const string& str)
	{
		for (char const& c : str) 
		{
			if (std::isdigit(c) == 0) return false;
		}
		return true;
	}
};
