#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int maxrow = 10;

string EmpName[maxrow] = {};
string EmpID[maxrow];

int main () {
    
    std::cout << "What's your pleasure?\n";
    int option;
    system("CLS");

    cout << "What's your pleasure?" << endl;
    cout << "1-Create Records" << endl;
    cout << "2-Read Records" << endl;
    cout << "3-Update Records" << endl;
    cout << "4-Delete Records" << endl;
    cout << "5-Exit" << endl;
    cout << "Enter your choice: ";
    //cin >> choice;
    cin.ignore();
    
    
    
    
    
    
    
    
    bool userChoice = false;
    string userInput;

    //Print initial list of employees


    // Repeat main loop 
    
    
    
    
    
    
    // Create a text file
  ofstream MyWriteFile("filename.txt");

  // Write to the file
  MyWriteFile << "Files can be tricky, but it is fun enough!";
 
  // Close the file
  MyWriteFile.close();

  // Create a text string, which is used to output the text file
  string myText;

  // Read from the text file
  ifstream MyReadFile("filename.txt");

  // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, myText)) {
    // Output the text from the file
    cout << myText;
  }

  // Close the file
  MyReadFile.close();
}