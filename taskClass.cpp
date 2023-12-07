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
    localtime_s(&this->dueDate, &curr);
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
    localtime_s(&tA, &timeA);
    localtime_s(&tB, &timeB);

    tA.tm_mday = dueDate.tm_mday;
    tA.tm_mon = dueDate.tm_mon - 1;
    tA.tm_year = dueDate.tm_year;

    tB.tm_year += 1900;

    timeA = mktime(&tA);
    timeB = mktime(&tB);

    timeLeft = difftime(timeA, timeB);

    return timeLeft;
}

bool conflicting(Task t1, int st1, int et1) {
    int st2 = t1.getIntStartTime();
    int et2 = t1.getIntEndTime();
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

string intTimeToTime(int time) {
    int hours, minutes;
    string sTime;
    hours = time / 60;
    minutes = time % 60;
    sTime = to_string(hours) + ':';
    if (minutes < 10)
        sTime += '0';
    sTime += to_string(minutes);
    return sTime;
}

void Task::loadSavedTask(ifstream& in) {
    string add;
    in >> taskName;
    while (in.peek() == ' ') {
        in >> add; // getting additional input
        taskName += " " + add; //updating our search key that we use to compare later
    }
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(in, taskDescription);
    in >> dueDate.tm_mon; in >> dueDate.tm_mday; in >> dueDate.tm_year;
    in >> startTime; in >> endTime;
}