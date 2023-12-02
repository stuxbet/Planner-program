#include "Functions.h"

int main()
{
    // days will be refrenced frorm 0 to 6 in order starting from monday
    vector<Linked> days;
    days.push_back(Linked());
    days.push_back(Linked());
    days.push_back(Linked());
    days.push_back(Linked());
    days.push_back(Linked());
    days.push_back(Linked());
    days.push_back(Linked());

    bool continu = true;
    while (continu == true) {
        continu = mainMenu(days);
    }


}
