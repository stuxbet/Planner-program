#pragma once
#include <iostream>
#include <string>

using namespace std;

bool mainMenu();
void addTaskToList(string DOW, string title, string description, string ST, string ET);
void deleteTask(string title);
void printItenerary();
void Help();
