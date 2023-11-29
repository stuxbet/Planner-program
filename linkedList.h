#pragma once
#include <string>
#include <iostream>
#include "taskClass.h"
using namespace std;

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
    void printList();
};