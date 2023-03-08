#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
using namespace std::chrono;
using namespace std;

struct NODEDLL
{
	string PhoneNumber; string Name;
	NODEDLL* previous, * next;
	NODEDLL()
	{
		previous = next = NULL; 
	}
};

class DoubleLinkedList
{
protected:
	NODEDLL* Head, * tail;
public:
	DoubleLinkedList()
	{
		Head = tail = NULL;
	}
	~DoubleLinkedList()
	{
		delete Head;
		delete tail;
		Head = tail = NULL;
	}
	bool INSERT_DLL(string PH,string name) 
	{
		NODEDLL* NewNode = new NODEDLL;
		if (Head == NULL)
		{
			NewNode->PhoneNumber = PH;
			NewNode->Name = name;
			NewNode->next = NULL;
			NewNode->previous = NULL;
			Head = tail = NewNode;
			return true;
		}
		else
		{
			NewNode->PhoneNumber = PH;
			NewNode->Name = name;
			NewNode->previous = tail;
			NewNode->next = NULL;
			NewNode->previous->next = NewNode;
			tail = NewNode;
			return true;
		}
	}
	void SORTING_DLL()
	{
		for (NODEDLL* i = Head; i != NULL; i = i->next)
		{
			for (NODEDLL* j = i; j != NULL; j = j->next)
			{
				if (i->Name > j->Name)
				{
					swap(j->Name, i->Name);
					swap(j->PhoneNumber, i->PhoneNumber);
				}
			}
		}
	}
	bool DELETE_DLL(string key)
	{
		NODEDLL* deleteTraverser, * temp;
		deleteTraverser = Head;
		while (deleteTraverser != tail)
		{
			if (deleteTraverser->Name == key)
			{
				temp = Head;
				Head = Head->next;
				delete temp;
				return true;
				break;
			}
			if (deleteTraverser->next->Name == key) 
			{
				temp = deleteTraverser->next;
				deleteTraverser->next = deleteTraverser->next->next;
				delete temp;
				return true;
				break;
			}
			deleteTraverser = deleteTraverser->next;
		}
		if (deleteTraverser == tail)
		{
			return false;
		}
	}
	void SEARCH_DLL(string key)
	{
		NODEDLL* temp;
		temp = Head;
		while (temp != tail)
		{
			if (temp->Name == key)
			{
				//cout << "Name: " << temp->Name << "\n";
				//cout << "Phone Number #" << temp->PhoneNumber << "\n\n";
				break;
			}
			temp = temp->next;
		}
		if (temp == tail)
		{
			//cout << "\n\n\tNumber Not Found\n";
		}
	}
	void DISPLAY_DLL() 
	{
		NODEDLL* curr = Head;
		cout << "Name\t\t\t\t\t\tPhone Number\n";
		while (curr != NULL)
		{
			cout << curr->Name << "\t\t\t\t\t\t\t\t"<<curr->PhoneNumber<<"\n";
			curr = curr->next;
		}
	}
	bool UPDATE_DLL(string prevName, string newName, string newPH)
	{
		NODEDLL* temp;
		temp = Head;
		while (temp != tail)
		{
			if (temp->Name == prevName)
			{
				temp->Name = newName;
				temp->PhoneNumber= newPH;
				Head = temp;
				return true;
				break;
			}
			temp = temp->next;
		}
		if (temp == tail)
		{
			return false;
		}
	}
	void READ_DLL()
	{
		string ph, name;//dummy variables
		ifstream read;
		read.open("DATA.csv", ios::in);
		string line;
		if (!read.is_open())
		{
			//cout << "\n\nCONTACTS FILE NOT FOUND\n\n";
		}
		auto start = high_resolution_clock::now();
		while (getline(read, line))
		{
			stringstream ss(line);
			getline(ss, ph, ',');
			getline(ss, name, ',');
			INSERT_DLL(ph, name);
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "\nTime to insert in the all the data from file in doubly link list: " << duration.count() << " microseconds\n" << endl;
		read.close();
	}
	void reWRITE_FILE()
	{
		SORTING_DLL();
		char oldname[] = "DATA.csv";
		char newname[] = "DATAnew.csv";
		fstream fin, fout;
		fin.open("DATA.csv", ios::in);
		//creating new file
		fout.open("DATAnew.csv", ios::out);
		NODEDLL* curr = Head;
		while (curr != NULL)
		{
			fout << curr->PhoneNumber <<"," << curr->Name << "\n";
			curr = curr->next;
		}
		fin.close();
		fout.close();
		//removing existing file
		remove("DATA.csv");
		rename("DATAnew.csv", "DATA.csv");
	}
};