#include "linkedList.h"
#include "Functions.h"

void Linked::addNode(Task t) {
    Node* tempNode = new Node;
    tempNode->task = t;
    tempNode->nextPtr = nullptr;
    if (headPtr == nullptr){
        headPtr = tempNode;
        tailPtr = tempNode;
    }
    else {
        tailPtr->nextPtr = tempNode;
        tailPtr = tempNode;
    }
}
void Linked::delNode(string name) {
    Node* tempNode = headPtr;
    Node* delNode;
    if (tempNode != nullptr && upper(tempNode->task.getTaskName()) == upper(name)){
        headPtr = headPtr->nextPtr;
        delete tempNode;
        tempNode = nullptr;
    }
    else{
        while(tempNode != nullptr && tempNode->nextPtr!=nullptr){
            if (tempNode->nextPtr->task.getTaskName() == name){
                delNode = tempNode->nextPtr;
                tempNode->nextPtr = tempNode->nextPtr->nextPtr;
                if (tempNode->nextPtr == tailPtr )
                    tailPtr = tempNode;
                delete delNode;
                delNode = nullptr;
            }
            tempNode = tempNode->nextPtr;
        }
    }
}

bool Linked::isEmpty(){
    if(headPtr == nullptr)
        return true;
    else
        return false;
}

void Linked::printList(int day) {
    string weekDay;
    switch (day) {
        case 1:
            weekDay = "MONDAY";
            break;
        case 2:
            weekDay = "TUESDAY";
            break;
        case 3:
            weekDay = "WEDNESDAY";
            break;
        case 4:
            weekDay = "THURSDAY";
            break;
        case 5:
            weekDay = "FRIDAY";
            break;
        case 6:
            weekDay = "SATURDAY";
            break;
        case 7:
            weekDay = "SUNDAY";
            break;
    }

    cout << "Here are your active tasks for " << weekDay << ":" << endl;
    Node* tempNode = headPtr;
    int num = 1;
    while(tempNode != nullptr){
        cout << "|-------------------------------------------------------------------------------------|" << endl;
        cout << setw(5) << left << "| " << setw(5) << left << "TASK NUMBER: " << num << setw(68) << right << "|" << endl;
        cout << "|-------------------------------------------------------------------------------------|" << endl;
        cout << setw(5) << left << "| " << setw(5) << left << "TASK TITLE: " << setw(38) << left << tempNode->task.getTaskName() << setw(32) << right << "|" << endl;
        cout << "|-------------------------------------------------------------------------------------|" << endl;
        cout << setw(5) << left << "|  " << setw(5) << left << "TASK DESCRIPTION: "<< setw(42) << left << tempNode->task.getTaskDescription() << setw(22) << right << "|" << endl;
        cout << "|-------------------------------------------------------------------------------------|" << endl;
        if(tempNode->task.getStartTime() != "00:00"){
            cout << setw(5) << left << "| " << setw(5) << left << "TIME BLOCK: " << setw(70) << right << "|" << endl;
            cout << "|-------------------------------------------------------------------------------------|" << endl;
        }
        if(tempNode->task.getDueDate().tm_year != 0){
            double time = tempNode->task.getTimeRemaining();
            cout << setw(5) << left << "| " << setw(5) << left << "TIME REMAINING UNTIL DUE: ";
            if(time/60/60 > 24) {
                cout << setw(2) << left << time / 60 / 60 / 24 << " days" << setw(49) << right << "|" << endl;
            }
            else
                cout << "< " << time / 60 / 60  << setw(4) << left << " hours" << setw(46) << right << "|" << endl;
            cout << "|-------------------------------------------------------------------------------------|" << endl;
        }
        cout << endl;
        tempNode = tempNode->nextPtr;
    }
}