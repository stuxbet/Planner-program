#include "taskClass.h"

using namespace std;

Task::Task() {
    taskName = "NAME";
    taskDescription = "DESCRIPTION";
    startTime = "00:00";
    endTime = "00:00";
    dueDate.tm_year = 0;
    dueDate.tm_mon = 0;
    dueDate.tm_mday = 0;

}

void Task::setTaskName(string name){
    taskName = name;
}

void Task::setTaskDescription(string desc){
    taskDescription = desc;
}

void Task::completeTask(){
    isCompleted = true;
}

void Task::setDueDate(int mon, int day, int year){

    time_t curr;
    this->dueDate = *localtime(&curr);
    this->dueDate.tm_year = year;
    this->dueDate.tm_mon = mon;
    this->dueDate.tm_mday = day;
    mktime(&this->dueDate);

}

double Task::getTimeRemaining(){

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

void Task::setStartTime(string time) {
    startTime = time;
}

void Task::setEndTime(string time) {
    endTime = time;
}

void Task::loadSavedTask(ifstream& in){
    string add;
    in >> taskName;
    while(in.peek() == ' ') {
        in >> add; // getting additional input
        taskName += " " + add; //updating our search key that we use to compare later
    }
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(in,taskDescription);
    in >> dueDate.tm_mon; in >> dueDate.tm_mday; in >> dueDate.tm_year;
    in >> startTime; in >> endTime;
}
