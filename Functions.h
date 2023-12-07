#pragma once
#include "linkedList.h"

using namespace std;

bool mainMenu(vector<Linked>&);
void printItinerary(vector<Linked>& days);
void Help();
string upper(string str);
void saveData(ofstream&, vector<Linked>&);
void readData(ifstream&, vector<Linked>&);
