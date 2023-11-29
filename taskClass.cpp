#include "taskClass.h"

using namespace std;

void Task::setTaskName(string name){
    taskName = name;
}

void Task::setTaskDescription(string desc){
    taskDescription = desc;
}

void Task::completeTask(){
    isCompleted = true;
}