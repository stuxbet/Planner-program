#include "taskClass.h"

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

void Task::setTaskName(string name) {
    taskName = name;
}

void Task::setTaskDescription(string desc) {
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

void Task::setDueDate(int day, int mon, int year) {

    time_t curr;
    this->dueDate = *localtime(&curr);
    this->dueDate.tm_year = year;
    this->dueDate.tm_mon = mon;
    this->dueDate.tm_mday = day;
    mktime(&this->dueDate);

}

void Task::completeTask() {
    isCompleted = true;
}

tm Task::getDueDate() {
    return dueDate;
}

double Task::getTimeRemaining() {

    double timeLeft;
    time_t timeA, timeB;
    tm tA, tB;
    time(&timeA);
    time(&timeB);
    tA = *localtime(&timeA);
    tB = *localtime(&timeB);

    tA.tm_mday = dueDate.tm_mday;
    tA.tm_mon = dueDate.tm_mon - 1;
    tA.tm_year = dueDate.tm_year;

    tB.tm_year += 1900;

    timeA = mktime(&tA);
    timeB = mktime(&tB);

    timeLeft = difftime(timeA, timeB);

    return timeLeft;
}

bool conflicting(Task& t1, Task& t2) {
    int st1 = t1.getIntStartTime();
    int et1 = t1.getIntEndTime();
    int st2 = t2.getIntStartTime();
    int et2 = t2.getIntEndTime();
    if (st1 >= et2 || st2 >= et1)
        return false;
    if (et1 <= st2 || et2 <= st1)
        return false;
    return true;
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

