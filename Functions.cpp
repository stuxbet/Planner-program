#include "Functions.h"

using namespace std;

bool mainMenu(vector<Linked>& days) {

	char userInput;
	cout << "Please select from one of the following: " << endl << endl;
	cout << "Enter A to add a Task" << endl;
    cout << "Enter C to complete a Task" << endl;
	cout << "Enter D to Delete a Task" << endl;
	cout << "Enter P to Print your planner" << endl;
    cout << "Enter H for help using this program" << endl;
    cout << "Enter Q to quit" << endl<<endl;
    cout << "->";
    cin >> userInput;
    userInput = toupper(userInput);

    
    //placeholder vaiables
    string DOW;
    string description;
    string ST;
    string ET;
    string title;
    int dayChoice;
    Task temp;

    switch (userInput) {
        case 'A':

            cout << "You selected Add Task." << endl;
            cout << "For which day would you like to add this task?" << endl;
            cout << "(Enter the corresponding number to select that day)\n";
            cout << "1.) Monday\n2.) Tuesday\n3.) Wednesday\n4.) Thursday\n5.) Friday\n6.) Saturday\n7.) Sunday" << endl;
            cin >> dayChoice;

            cout << "Please enter the task Name/Title" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, title);

            cout << "Please enter the task description" << endl;
            getline(cin, description);

            temp.setTaskName(title);
            temp.setTaskDescription(description);

            cout << "Would you like to add a due date for this task?(Enter Y for yes or N for no):  ";
            char exChoice;
            cin >> exChoice;
            cout << endl;
            if (toupper(exChoice == 'Y')) {
                cout << "Enter the due date (MM/DD/YYYY): ";
                string date;
                cin >> date;
                stringstream inSS(date);
                int m, d, y;
                inSS >> m;
                inSS.ignore(1);
                inSS >> d;
                inSS.ignore(1);
                inSS >> y;
                temp.setDueDate(m, d, y);
                cout << "Due date for this task is set to " << date << "." << endl;
            }

            cout << "Do you want to time block this task?(Enter Y for yes or N for no): " << endl;
            cin >> exChoice;
            cout << endl;
            if (toupper(exChoice == 'Y')) {
                cout << "Please enter start time of task (Enter in HH:MM format)" << endl;
                getline(cin, ST);
                cout << "Please enter End time of task (Enter in HH:MM format)" << endl;
                getline(cin, ET);
            }
            days.at(dayChoice - 1).addNode(temp);
            cout << "The task \"" << title << "\" has been added." << endl;
            days.at(dayChoice - 1).printList(dayChoice);
            return true;
        case 'D':
            cout << "1.) Monday\n2.) Tuesday\n3.) Wednesday\n4.)Thursday\n5.)Friday\n6.)Saturday\n7.)Sunday" << endl;
            cout << "Please choose a day: "; cin >> dayChoice;
            if(days.at(dayChoice-1).isEmpty())
                cout << "There are no tasks set for this day." << endl;
            else{
                days.at(dayChoice-1).printList(dayChoice);
                cout << "Enter the title of the task you would like to delete: "; getline(cin,title);
                days.at(dayChoice-1).delNode(title);
                cout << "Task \"" << title << "\" has been deleted" << endl;
            }
            return true;
        case 'H':
            Help();
            return true;
        case 'C':
            cout << "1.) Monday\n2.) Tuesday\n3.) Wednesday\n4.)Thursday\n5.)Friday\n6.)Saturday\n7.)Sunday" << endl;
            cout << "Please choose a day: "; cin >> dayChoice;
            if(days.at(dayChoice-1).isEmpty())
                cout << "There are no tasks set for this day." << endl;
            else{
                days.at(dayChoice-1).printList(dayChoice);
                cout << "Enter the title of the task you would like to complete: "; getline(cin,title);
                days.at(dayChoice-1).delNode(title);
                cout << "Task \"" << title << "\" has been completed" << endl;
            }
            return true;
        case 'P':
            //printItinerary();
            return true;
        default:
            return false;
    }
}

void printItinerary(vector<Linked>& days) {


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

string upper(string str){
    for(int i = 0; i < str.size(); i++) {
        str.at(i) = toupper(str.at(i));
    }
    return str;
}

int dayToIterator(string DOW) {
    switch (tolower(DOW.at(0))) {
    case 'm':
        return 0;
    case 't':
        if (tolower(DOW.at(1)) == 'u')
            return 1;
        else
            return 3;
    case 'w':
        return 2;
    case 'f':
        return 4;
    case 's':
        if (tolower(DOW.at(1)) == 'a')
            return 5;
        else
            return 6;
    default:
        cout << "Invalid Day";
        return -1;
    }
}
