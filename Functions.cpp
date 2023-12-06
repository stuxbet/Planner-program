#include "Functions.h"

using namespace std;

bool mainMenu(vector<Linked>& days) {

	char userInput;
	cout << "Please select from one of the following: " << endl << endl;
	cout << "Enter A to add a Task" << endl;
    cout << "Enter V to view your tasks by day" << endl;
	cout << "Enter D to Delete/Complete a Task" << endl;
	cout << "Enter P to Print your planner for the week" << endl;
    cout << "Enter H for help using this program" << endl;
    cout << "Enter Q to quit" << endl<<endl;
    cout << "->";
    cin >> userInput;
    userInput = toupper(userInput);
    if(!((toupper(userInput) == 'A' ) || (toupper(userInput) == 'V') || (toupper(userInput) == 'D') || (toupper(userInput) == 'P') || (toupper(userInput) == 'H') || (toupper(userInput) == 'Q')))
        throw runtime_error("ERROR: Invalid input");

    
    //placeholder variables
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
            cout << "For which day would you like to add this task?\n" << endl;
            cout << "(Enter the corresponding number to select that day):" << endl;
            cout << "1.) Monday\n2.) Tuesday\n3.) Wednesday\n4.) Thursday\n5.) Friday\n6.) Saturday\n7.) Sunday" << endl;
            cout << "-> "; cin >> dayChoice; cout << endl;

            cout << "Please enter the task Name/Title: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, title);
            cout << endl;

            cout << "Please enter the task description: ";
            getline(cin, description);
            cout << endl;

            temp.setTaskName(title);
            temp.setTaskDescription(description);

            cout << "Would you like to add a due date for this task?(Enter Y for yes or N for no):  ";
            char exChoice;
            cin >> exChoice;
            cout << endl;
            if (toupper(exChoice ) == 'Y') {
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
                cout << "\nDue date for the task \"" << title << "\" is set to " << date << ".\n" << endl;
            }

            cout << "Do you want to time block this task?(Enter Y for yes or N for no): ";
            cin >> exChoice;
            cout << endl;
            if (toupper(exChoice) == 'Y') {
                cout << "Please enter start time of task (Enter in HH:MM format): ";
                cin >> ST;
                cout << "\nPlease enter End time of task (Enter in HH:MM format): ";
                cin >> ET;
                cout << endl;
                temp.setStartTime(ST);
                temp.setEndTime(ET);
            }
            days.at(dayChoice - 1).addNode(temp);
            cout << "The task \"" << title << "\" has been added.\n" << endl;
            days.at(dayChoice - 1).printList(dayChoice);
            return true;
        case 'D':
            cout << "(Enter the corresponding number to select that day):" << endl;
            cout << "1.) Monday\n2.) Tuesday\n3.) Wednesday\n4.) Thursday\n5.) Friday\n6.) Saturday\n7.) Sunday" << endl;
            cout << "Please choose a day: "; cin >> dayChoice;
            if(days.at(dayChoice-1).isEmpty())
                cout << "\nUNABLE TO PROCESS COMMAND: There are no tasks set for this day." << endl;
            else{
                days.at(dayChoice-1).printList(dayChoice);
                cout << "Enter the title of the task you would like to delete: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, title);
                days.at(dayChoice-1).delNode(title);
            }
            return true;
        case 'V':
            cout << "(Enter the corresponding number to select that day):" << endl;
            cout << "1.) Monday\n2.) Tuesday\n3.) Wednesday\n4.) Thursday\n5.) Friday\n6.) Saturday\n7.) Sunday" << endl;
            cout << "Please choose a day: "; cin >> dayChoice;
            if(days.at(dayChoice-1).isEmpty())
                cout << "\nYou have no active tasks for the selected day." << endl;
            else
                days.at(dayChoice-1).printList(dayChoice);
            return true;
        case 'H':
            Help();
            return true;
        case 'P':
            printItinerary(days);
            return true;
        default:
            return false;
    }
}

void printItinerary(vector<Linked>& days) {
vector<string> dayWords = {"MONDAY","TUESDAY","WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY"};
    for(int i = 0; i < days.size(); i++){
        cout << "++++++++++++++++++++++++++++++++++++++++ " << dayWords.at(i) << " ++++++++++++++++++++++++++++++++++++++++\n" << endl;
        if(days.at(i).isEmpty())
            cout << "There are no tasks active for today." << endl;
        else{
            days.at(i).printList(i+1);
        }
        cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
    }
}
void Help() {
    cout << "\nYou have selected help" << endl;
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

void saveData(ofstream& save, vector<Linked>& days){
    int size;
    for(int i = 0; i < days.size(); i++){
        size = days.at(i).getSize();
        if(size == 0){
            save << size << endl;
        }
        else{
            save << size << endl;
            days[i].saveList(save);
        }
    }
}

void readData(ifstream& in, vector<Linked>& days){
    int x;
    Task temp;
    for(int i = 0; i < days.size(); i++){
        in >> x ;
        for(int y = 0; y < x; y++){
            temp.loadSavedTask(in);
            days.at(i).addNode(temp);
        }
    }
}