#include "Functions.h"

using namespace std;

int main() {

    Linked monday,tuesday, wednesday, thursday, friday, saturday, sunday;
    vector<Linked> days = {monday,tuesday, wednesday, thursday, friday, saturday, sunday};

    cout << "\n" << endl;
    while(mainMenu(days));
    //saveFile.open("saveData.txt");
    //saveData(days,saveFile);

    return 0;
}
