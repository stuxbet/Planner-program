#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

class Task{
private:
    string taskName;
    string taskDescription;
    tm dueDate;
    string startTime;
    string endTime;
    bool isCompleted;
public:
    Task();
    void setTaskName(string);
    void setTaskDescription(string);
    void setDueDate(int, int, int);
    void setStartTime(string);
    void setEndTime(string);
    void completeTask();
    void loadSavedTask(ifstream&);
    string getTaskName() {return taskName;}
    string getTaskDescription() {return taskDescription;}
    double getTimeRemaining();
    tm getDueDate() { return dueDate;}
    string getStartTime() { return startTime; }
    string getEndTime() { return endTime; }
};
