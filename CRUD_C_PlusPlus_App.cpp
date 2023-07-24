#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

vector<string> EmpID;
vector<string> EmpName;
int maxrow = 0; // declare and initialize maxrow variable

void AddRecord()
{
    string name;
    string empno;

    cout << "Employee ID: ";
    cin >> empno;

    // Validate input for empno
    while (cin.fail() || empno.find_first_not_of("0123456789") != string::npos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Please enter a valid employee ID (text only): ";
        cin >> empno;
    }

    cout << "Employee Name: ";
    cin.ignore();
    getline(cin, name);

    EmpID.push_back(empno);
    EmpName.push_back(name);
    maxrow = EmpID.size(); // update maxrow to reflect new size of vectors
}

void ListRecord()
{
    system("CLS");
    cout << "Current Record(s)" << endl;
    cout << "=================================" << endl;

    int counter = 0;
    cout << " No.   |    ID     NAME    " << endl << "-----------------------------------\n";
    for (int x = 0; x < maxrow; x++)
    {
        if (!EmpID[x].empty())
        {
            counter++;
            cout << "   " << counter << "      " << EmpID[x] << "         " << EmpName[x] << endl;
        }
    }
}

int main()
{
    int choice;

    do
    {
        system("CLS");
        cout << "Employee Record System" << endl;
        cout << "=========================" << endl;
        cout << "1. Create Record" << endl;
        cout << "2. Display Record" << endl;
        cout << "3. Update Record" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddRecord();
            break;
        case 2:
            ListRecord();
            break;
        case 3:
            // TODO: implement update record function
            break;
        case 4:
            // TODO: implement delete record function
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        system("PAUSE");

    } while (choice != 5);

    return 0;
}