#pragma once
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Task{
private:
    string taskName;
    string taskDescription;
    bool isCompleted;
    tm dueDate;
public:
    void setTaskName(string);
    void setTaskDescription(string);
    void setDueDate(int, int, int);
    void completeTask();
    string getTaskName() {return taskName;}
    string getTaskDescription() {return taskDescription;}
    double getTimeRemaining();
    bool getStatus() {return isCompleted;}
};
