#pragma once
#include <iostream>
#include <string>
#include <functional>
using namespace std;

//using template and creating class called hashtableentry
template <typename K, typename T>
struct node
{
	K Key;
	T Value;

	node<T, K>* nextHash = NULL;
};
//using template and creating a class called hashtable
template <typename K, typename T>
class HashTable
{
	//private data used in the class
private:
	//T tableSize = 256;
	node<K, T>* table[256] = { NULL };
public:
	//constructor
	HashTable()
	{
		//node<K, T>* table[128] = new node<K, T>* table[128];
	}
	//void to insert a node
	void insert(K insertedKey, T new_data)
	{
		//takes the inserted key and runs it throygh a hahs key
		K hashedKey = hashInserted(insertedKey);
		//if there is no node at the pointed spot on the table set that spot to the key and value
		if (table[hashedKey] == NULL)
		{
			table[hashedKey] = new node<K, T>();
			table[hashedKey]->Key = insertedKey;
			table[hashedKey]->Value = new_data;
		}
		//otherwise take the existing value and rewrites it with the new value entered along with creating a list and the location
		//with the key and old value foe future reference
		else
		{
			node<K, T>* temp = table[hashedKey];
			K old_data = temp->Value;
			if (temp->Value == new_data)
			{
				cout << "Value is already in the list" << endl;
				return;
			}
			else
			{
				cout << "Value is rewriting the old value of " << old_data << " with the new value of " << new_data << endl;
				temp->Value = new_data;
			}
			while (temp->nextHash != NULL)
			{
				temp = temp->nextHash;
				if (temp->Value == new_data)
				{
					return;
				}
				else
				{
					temp->Value = new_data;
				}
			}
			temp->nextHash = new node<K, T>();
			temp->nextHash->Key = insertedKey;
			temp->nextHash->Value = old_data;

		}
	}
	void find(K key_to_find)
	{
		//takes the inserted key and hashes it
		K hashedKey = hashInserted(key_to_find);
		//if nothing there return no value/key found
		if (table[hashedKey] == NULL)
		{
			cout << "Value not found" << endl;
		}
		//otherwise create a temp node at the location and then display the key and value found
		else
		{
			node<K, T>* temp = table[hashedKey];
				cout << "The key input is: " << temp->Key << endl;
				cout << "The value in that key is: " << temp->Value << endl;
		}
	}
	//boid for showing the data in the array
	void show()
	{
		//starts off at the beining of the list then looks through the entire list while displaying any node keys and values found
		for (T i = 0; i < 256; i++)
		{
			if (table[i] != NULL)
			{
				cout << "Key is " << table[i]->Key << " ";
				cout << "Value is " << table[i]->Value << " ";
			}
		}
		cout << "All nodes shown" << endl;

	}

	void del(K data_to_delete)
	{
		//will run the data through the find function then delete when the data is found
	}

	//void that takes the inserted kew and hashes the value based on table size
	K hashInserted(K keyToHash)
	{
		size_t hashBase = hash<K>() (keyToHash);
		K hashedKey = hashBase % 256;
		return hashedKey;
	}
};