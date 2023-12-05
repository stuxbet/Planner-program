#pragma once
#include "taskClass.h"

struct Node {
    Task task;
    Node* nextPtr;
};

class Linked {
private:
    Node* headPtr;
    Node* tailPtr;
public:
    Linked();
    Linked(Task t);
    void addNode(Task t);
    void delNode(string name);
    bool taskConflict(int& st, int& et);
    void printList(int day);
    bool isEmpty();
};
string upper(string str);