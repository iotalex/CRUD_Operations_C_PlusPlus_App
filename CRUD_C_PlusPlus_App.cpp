#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

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

    // Validate input for name
    while (name.empty() || !all_of(name.begin(), name.end(), ::isalpha)) {
        cout << "Invalid response, please enter employee's name: ";
        getline(cin, name);
    }

    EmpID.push_back(empno);
    EmpName.push_back(name);
    maxrow = EmpID.size(); // update maxrow to reflect new size of vectors
}

void ListRecord()
{
    system("CLS");
    cout << "Current Record(s)" << endl;
    cout << "=================================" << endl;

    // Sort employee records by name
    vector<string> sortedEmpName = EmpName;
    sort(sortedEmpName.begin(), sortedEmpName.end());

    int counter = 0;
    cout << " No.   |    ID     NAME    " << endl << "-----------------------------------\n";
    for (int x = 0; x < maxrow; x++)
    {
        if (!EmpID[x].empty())
        {
            counter++;
            // Find index of employee record in sortedEmpName vector
            int index = find(EmpName.begin(), EmpName.end(), sortedEmpName[x]) - EmpName.begin();
            cout << "   " << counter << "      " << EmpID[index] << "         " << sortedEmpName[x] << endl;
        }
    }
}

void UpdateRecord()
{
    system("CLS");
    cout << "Update Record" << endl;
    cout << "=================================" << endl;

    // Display list of employee IDs and names
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

    // Prompt user to enter employee ID to update
    string empno;
    bool validEmpno = false;
    do {
        cout << "Enter employee ID to update: ";
        cin >> empno;

        // Check if employee ID is valid
        if (cin.fail() || empno.find_first_not_of("0123456789") != string::npos) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please enter a valid employee ID (text only)." << endl;
        }
        else {
            int index = -1;
            for (int i = 0; i < maxrow; i++)
            {
                if (EmpID[i] == empno)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                cout << "Error: Employee ID not found." << endl;
            }
            else
            {
                // Prompt user to enter new employee name
                string name;
                cout << "Enter new employee name: ";
                cin.ignore();
                getline(cin, name);

                // Prompt user to update employee ID
                string updateID;
                cout << "Would you like to update the employee ID? (yes or no): ";
                cin >> updateID;

                if (updateID == "yes") {
                    string newID;
                    cout << "Enter new employee ID: ";
                    cin >> newID;

                    // Check if new employee ID is valid
                    if (cin.fail() || newID.find_first_not_of("0123456789") != string::npos) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Error: Please enter a valid employee ID (text only)." << endl;
                    }
                    else {
                        EmpID[index] = newID;
                        cout << "Employee record updated successfully." << endl;
                        validEmpno = true;
                    }
                }
                else {
                    EmpName[index] = name;
                    cout << "Employee record updated successfully." << endl;
                    validEmpno = true;
                }
            }
        }
    } while (!validEmpno);

    system("PAUSE");
}

void DeleteRecord()
{
    system("CLS");
    cout << "Delete Record" << endl;
    cout << "=================================" << endl;

    // Display list of employee IDs and names
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

    // Prompt user to enter employee ID to delete
    string empno;
    bool validEmpno = false;
    do {
        cout << "Enter employee ID to delete: ";
        cin >> empno;

        // Check if employee ID is valid
        if (cin.fail() || empno.find_first_not_of("0123456789") != string::npos) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please enter a valid employee ID (text only)." << endl;
        }
        else {
            int index = -1;
            for (int i = 0; i < maxrow; i++)
            {
                if (EmpID[i] == empno)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                cout << "Wrong Employee ID entered, please try again." << endl;
            }
            else
            {
                EmpID.erase(EmpID.begin() + index);
                EmpName.erase(EmpName.begin() + index);
                maxrow = EmpID.size(); // update maxrow to reflect new size of vectors
                cout << "Employee record deleted successfully." << endl;
                validEmpno = true;
            }
        }
    } while (!validEmpno);
}

int main()
{
    int choice;

    do
    {
        // Add test data
        EmpID.push_back("1001");
        EmpName.push_back("John Smith");
        EmpID.push_back("1002");
        EmpName.push_back("Jane Doe");
        EmpID.push_back("1003");
        EmpName.push_back("Bob Johnson");
        maxrow = 3;

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
            UpdateRecord();
            break;
        case 4:
            DeleteRecord();
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