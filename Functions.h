#pragma once
#include "linkedList.h"


using namespace std;

bool mainMenu(vector<Linked>& days);
int dayToIterator(string DOW);
void addTaskToList(vector<Linked>& days, string DOW, string title, string description, string ST, string ET);
void deleteTask(vector<Linked>& days, string title);
void printItenerary(vector<Linked>& days);
void Help();
