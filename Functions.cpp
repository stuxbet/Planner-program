#include "Functions.h"
#include <iostream>
#include <string>
using namespace std;

bool mainMenu() {
	char userInputchar = 'l';
	string userInput;
	cout <<"Welcome to the Week Planner"<< endl<<endl;
	cout << "Please select from one of the following" << endl << endl;
	cout << "Enter A to add a Task" << endl;
	cout << "Enter D to Delete a Task" << endl;
	cout << "Enter P to Print your planner" << endl;
    cout << "Enter H for help using this program" << endl;
    cout << "Enter Q to quit" << endl<<endl;
    cout << "->";
    cin >> userInput;
	userInputchar = toupper(userInput[0]);

    switch (userInputchar) {
    case 'A':
        cout << "You selected option 1." << endl;
        return true;

    case 'D':
        cout << "You selected option 2." << endl;
        return true;

    case 'P':
        cout << "You selected option 3." << endl;
        return true;

    case 'H':
        cout << "You selected option 4." << endl;
        return true;
    case 'Q':
        cout << "You choose to quit, oodbye" << endl;
        return false;

    default:
        cout << "Invalid choice." << endl;
        return true;
    }



}
