#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Task{
private:
    string taskName;
    string taskDescription;
    tm dueDate;
    string startTime;
    string endTime;
    int intStartTime;
    int intEndTime;
    bool isCompleted;
public:
    Task();
    void setTaskName(string);
    void setTaskDescription(string);
    void setDueDate(int, int, int);
    void completeTask();
    string getTaskName() {return taskName;}
    string getTaskDescription() {return taskDescription;}
    double getTimeRemaining();
    tm getDueDate() { return dueDate;}
    string getStartTime() { return startTime; }
    string getEndTime() { return endTime; }
    int getIntStartTime() { return intStartTime; }
    int getIntEndTime() { return intEndTime; }
    bool getStatus() {return isCompleted;}
};
