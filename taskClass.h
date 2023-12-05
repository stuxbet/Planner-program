#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

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
    Task(string, string, string, string, bool);
    void setTaskName(string);
    void setTaskDescription(string);
    void setStartTime(string);
    void setEndTime(string);
    void completeTask();
    void setDueDate(int, int, int);
    string getTaskName() { return taskName; }
    string getTaskDescription() { return taskDescription; }
    string getStartTime() { return startTime; }
    string getEndTime() { return endTime; }
    int getIntStartTime() { return intStartTime; }
    int getIntEndTime() { return intEndTime; }
    double getTimeRemaining();
    tm getDueDate();
    bool getStatus() { return isCompleted; }
};

bool conflicting(Task& t1, Task& t2);
int timeToIntTime(string time);