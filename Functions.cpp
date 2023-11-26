#include "Functions.h"
#include <iostream>
#include <string>
using namespace std;

bool mainMenu() {
	char userInputchar = 'l';
	string userInput;
	cout << "Please select from one of the following" << endl << endl;
	cout << "Enter A to add a Task" << endl;
	cout << "Enter D to Delete a Task" << endl;
	cout << "Enter P to Print your planner" << endl;
    cout << "Enter H for help using this program" << endl;
    cout << "Enter Q to quit" << endl<<endl;
    cout << "->";
    cin >> userInput;
	userInputchar = toupper(userInput[0]);
    
    //placeholder vaiables
    string DOW;
    string description;
    string ST;
    string ET;
    string title;

    switch (userInputchar) {
    case 'A':

        cout << "You selected Add Task." << endl;
        cout << "Please enter task Name/Title" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, title);

        cout << "Please enter task discription" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, description);

        cout << "Please enter the day of the week that you will complete the task" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, DOW);

        cout << "Please enter start time of task" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, ST);
        cout << "Please enter End time of task" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, ET);       

        addTaskToList(DOW,title, description, ST, ET);

        return true;

    case 'D':
        cout << "You selected Add Task." << endl;
        cout << "Please enter task Name/Title to delete" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, title);
        deleteTask(title);
        return true;

    case 'P':
        void printItenerary();

        return true;

    case 'H':
        Help();
        return true;
    case 'Q':
        cout << "You choose to quit, Goodbye" << endl;
        return false;

    default:
        cout << "Invalid choice." << endl;
        return true;
    }



}
void addTaskToList(string DOW,string title, string description, string ST, string ET) {
    /*pre: dow(Day of week),title , description, ST(start time), ET(end time) are all passed and
    post:this simply makes a instance of the taskclass class and adds it to the list. it also might check to see if there are overlapping events
    */
    int x = 0;
    return;

}
void deleteTask(string title) {
    /*
    Pre: task title is passed
    post: deletes task from one of the given linked lists
    */
    int x = 0;
    return;
}
void printItenerary() {
    /*
    Pre:not entirely sure up to who write the function as to how they get the lists to the function
    Post: write a well formatted week itenerary to a designated outfile
    */
    int x = 0;
    return;

}
void Help() {
    cout << "You have selected help" << endl;
    cout << "This is the week planner program" << endl<<endl;
    cout << "To use this program you can add tasks for your week. " << endl;
    cout << "To add tasks select A in the main menu and fill out the start time, end time " << endl;
    cout << "Title, description, and the day of the week " << endl << endl;
    cout << "if you made a mistake you can delete the task by pressing D on the main menu" << endl;
    cout << "and entering the title of the task. " << endl<<endl;
    cout << "Once you are done press P on the main menu and it will create a txt " << endl;
    cout << "file that you can print off" << endl<<endl<<endl;
}
