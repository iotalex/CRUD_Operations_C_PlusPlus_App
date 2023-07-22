#include <iostream>
#include <string>
#include <fstream>


using namespace std;

const int maxrow = 10;

string EmpName[maxrow] = {};
string EmpID[maxrow] = {};

void AddRecord()
{
    char name[50];
    char empno[5];

    cin.ignore();

    cout << "Employee ID. ";
    cin.getline(empno, 5);
    cout << "Employee Name. ";
    cin.getline(name, 50);

    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == "\0")
        {
            EmpID[x] = empno;
            EmpName[x] = name;

            break;
        }
    }
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
        if (EmpID[x] != "\0")
        {
            counter++;
            cout << "   " << counter << "      " << EmpID[x] << "         " << EmpName[x] << endl;

            break;
        }
    }

}

int main () {
    
    std::cout << "What's your pleasure?\n";
    int option;
    system("CLS");

    do {
        cout << "1-Create Records" << endl;
        cout << "2-Read Records" << endl;
        cout << "3-Update Records" << endl;
        cout << "4-Delete Records" << endl;
        cout << "5-Search all Records" << endl;
        cout << "6-Exit & Save to Textfile" << endl;
        cout << "==================================" << endl;

        cout << "Select Option >>";
        cin >> option;

        switch (option)
        {
        case 1: AddRecord();
            system("CLS");
            break;
        
        case 5: ListRecord();
            break;
        }

       
    } while (option != 6);
    //cin >> choice;
      
    
}