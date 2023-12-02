#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Task{
private:
    string taskName;
    string taskDescription;
    string startTime;
    string endTime;
    int intStartTime; // The time you would use to check if a specified time falls in a task's time
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
    string getTaskName() { return taskName; }
    string getTaskDescription() { return taskDescription; }
    string getStartTime() { return startTime; }
    string getEndTime() { return endTime; }
    int getIntStartTime() { return intStartTime; }
    int getIntEndTime() { return intEndTime; }
    bool getStatus() { return isCompleted; }
};

int timeToIntTime(string time);

