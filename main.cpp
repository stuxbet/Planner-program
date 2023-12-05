#include "Functions.h"

using namespace std;

int main() {

    Linked monday, tuesday, wednesday, thursday, friday, saturday, sunday;
    vector<Linked> days = {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

    while(mainMenu(days));

    return 0;
}
