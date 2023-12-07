#include "Functions.h"

using namespace std;

int main() {

    Linked monday,tuesday, wednesday, thursday, friday, saturday, sunday;
    vector<Linked> days = {monday,tuesday, wednesday, thursday, friday, saturday, sunday};

    ifstream inFile;
    ofstream saveFile;
    inFile.open("saveData.txt");
    if (isdigit(inFile.peek())) {
        readData(inFile, days);
    }

    cout << "\n" << endl;
    while(mainMenu(days));

    saveFile.open("saveData.txt");
    saveData(saveFile, days);


    return 0;
}
