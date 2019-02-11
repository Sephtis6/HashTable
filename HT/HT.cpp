// HT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//heder called to use in the file
#include "pch.h"
#include "HT.h"
#include <iostream>
#include <string>
//declares the void and using namespace
using namespace std;
void DisplayUserCommands();
void Test();
//main void used
int main()
{
	//stores the data to be used and creates a new table for the user
	HashTable<int, int> my_table;
	int number;
	int table_key;
	int table_value;
	int table_size;
	//welcomes the user
	cout << "Welcome to the Hash Table assignment" << endl;
	//ask for the user to input a table size to use
	//cout << "Please enter the size of table that you want to use" << endl;
	//cin >> table_size;
	//my_table.tableSizeStart(table_size);
	//checkpoint that can be returnes to
start:
	//calling a function to display the list of user commands
	DisplayUserCommands();
	//get's the user's choice and does something based on it
	cout << "Please enter an option: " << endl;
	cin >> number;
	//does something based on the number the user picks
	switch (number)
	{
		//clears the system of outputs and then loads a function based on the number picked
	case 1:
		//allows the user to insert a key and value
		system("CLS");
		cout << "Please enter a key value to add to the list" << endl;
		cin >> table_key;
		cout << "please enter a value to add to the list" << endl;
		cin >> table_value;
		my_table.insert(table_key, table_value);
		goto start;
		break;
	case 2:
		//allows the user to find a specific key
		system("CLS");
		cout << "Please enter what key you want to find on the hash table" << endl;
		cin >> table_key;
		my_table.find(table_key);
		goto start;
		break;
	case 3:
		//allows the user to find a specific key
		system("CLS");
		cout << "Showing the nodes in the hash table" << endl;
		my_table.show();
		goto start;
		break;
	case 4:
		//allows the user to run the test program
		system("CLS");
		Test();
		goto start;
		break;
	case 5:
		//allows the user to exit from the program
		system("CLS");
		return 0;
		break;
	default:
		//ends the progrma if the user chooses something other then the given options
		cout << "You chose an unavailable option. Program will close soon." << endl;
		break;
	}
	//pauses the system and then ends the program
	system("pause");
	return 0;
}

// funtion to display the list of user commands
void DisplayUserCommands() {
	cout << "List of choices:" << endl;
	cout << "1 Insert data to the Hash Table" << endl;
	cout << "2 Search for a specific set of data froom the Hash Table" << endl;
	cout << "3 How the Hash Table nodes" << endl;
	cout << "4 Run the premade automated test" << endl;
	cout << "5 Exit out of the program" << endl;
}
//test void that goes through the functions of the table and diplays the results at vaious points in the process
void Test()
{
	HashTable <int, int> testTable;
	//testTable.tableSizeStart(128);
	testTable.show();
	testTable.find(10);
	testTable.insert(25, 30);
	testTable.insert(50, 100);
	testTable.insert(90, 540);
	testTable.insert(40, 500);
	testTable.insert(15, 250);
	testTable.insert(10, 10);
	testTable.show();
	cout << "Testing collisions" << endl;
	testTable.insert(10, 11);
	testTable.insert(20, 30);
	cout << "Displaying key 20 node" << endl;
	testTable.find(20);
	cout << "Adding new node" << endl;
	testTable.insert(100, 100);
	cout << "Displaying added node" << endl;
	testTable.find(100);
	cout << "Looking for node not in the list" << endl;
	testTable.find(200);
	testTable.show();
}