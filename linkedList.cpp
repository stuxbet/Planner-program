#include "linkedList.h"

Linked::Linked() {
    headPtr = nullptr;
    tailPtr = nullptr;
}
Linked::Linked(Task t) {
    Node* tempPtr = new Node;
    tempPtr->task = t;
    tempPtr->nextPtr = nullptr;
}

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
    if (tempNode != nullptr && tempNode->task.getTaskName() == name){
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
void Linked::printList() {
    Node* tempNode = headPtr;
    while(tempNode != nullptr){
        cout << tempNode->task.getTaskName() << endl;
        cout << tempNode->task.getTaskDescription() << endl;
        tempNode = tempNode->nextPtr;
    }
}