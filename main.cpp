#include "Functions.h"
#include "taskClass.h"

using namespace std;

int main() {

    Linked monday,tuesday, wednesday, thursday, friday, saturday, sunday;
    vector<Linked> days = {monday,tuesday, wednesday, thursday, friday, saturday, sunday};
    Task temp, temp2, temp3;

    cout << "\n" << endl;
    while(mainMenu(days));

    return 0;
}
