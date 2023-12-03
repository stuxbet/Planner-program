#include "taskClass.h"

using namespace std;

Task::Task() {
    taskName = "NAME";
    taskDescription = "DESCRIPTION";
    startTime = "00:00";
    endTime = "00:00";
    intStartTime = 0;
    intEndTime = 0;
    isCompleted = 0;
}

Task::Task(string name, string description, string ST, string ET, bool completed) {
    taskName = name;
    taskDescription = description;
    startTime = ST;
    endTime = ET;
    intStartTime = timeToIntTime(ST);
    intEndTime = timeToIntTime(ET);
    isCompleted = completed;
}

void Task::setTaskName(string name){
    taskName = name;
}

void Task::setTaskDescription(string desc){
    taskDescription = desc;
}

void Task::setStartTime(string time) {
    startTime = time;
    intStartTime = timeToIntTime(time);
}

void Task::setEndTime(string time) {
    endTime = time;
    intEndTime = timeToIntTime(time);
}

void Task::completeTask(){
    isCompleted = true;
}

int timeToIntTime(string time) { // Takes in a string 'time' and outputs the total amount of minutes
    stringstream ssTime(time);
    string tempStr;
    int hours, minutes;

    getline(ssTime, tempStr, ':');
    hours = stoi(tempStr);
    ssTime >> tempStr;
    minutes = stoi(tempStr);

    return hours * 60 + minutes;
}