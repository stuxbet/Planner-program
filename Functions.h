#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool mainMenu(vector<Linked> days);
void addTaskToList(vector<Linked> days, string DOW, string title, string description, string ST, string ET);
void deleteTask(vector<Linked> days, string title);
void printItenerary(vector<Linked> days);
void Help();
