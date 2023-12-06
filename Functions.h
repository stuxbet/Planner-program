#pragma once
#include "linkedList.h"
#include <vector>

using namespace std;

bool mainMenu(vector<Linked>&);
void printItinerary(vector<Linked>& days);
void Help();
string upper(string str);
int dayToIterator(string DOW);
void saveData(ofstream&, vector<Linked>&);
void readData(ifstream&, vector<Linked>&);
