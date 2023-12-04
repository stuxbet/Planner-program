#include "Functions.h"
#include "taskClass.h"

using namespace std;

int main() {

    Linked monday,tuesday, wednesday, thursday, friday, saturday, sunday;
    vector<Linked> days = {monday,tuesday, wednesday, thursday, friday, saturday, sunday};
    Task temp, temp2, temp3;
//    temp.setTaskName("homework");
//    temp2.setTaskName("review");
//    temp3.setTaskName("study");
//    temp2.setDueDate(12,24,2023);
//    monday.addNode(temp);
//    monday.addNode(temp2);
//    monday.addNode(temp3);
//    monday.printList(1);
//    monday.delNode("Reviefhhggh");
//    monday.printList(1);

    cout << "\n" << endl;
    while(mainMenu(days));

    return 0;
}
