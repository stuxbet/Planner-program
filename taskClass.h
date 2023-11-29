#pragma once
#include <iostream>
#include <string>

using namespace std;

class Task{
private:
    string taskName;
    string taskDescription;
    bool isCompleted;
public:
    void setTaskName(string);
    void setTaskDescription(string);
    void completeTask();
    string getTaskName() {return taskName;}
    string getTaskDescription() {return taskDescription;}
    bool getStatus() {return isCompleted;}
};
