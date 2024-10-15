#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // Include for sorting
using namespace std;

int main() {
    string name;
    int menu, count, number;
    vector<string> names; // Use a vector to store names
    ofstream outputFile;
    ifstream readFile;

    outputFile.open("LineUp.txt");

    cout << "Choose what you would like to do:\n"
        << "1. Enter names of students\n"
        << "2. Display names of students\n"
        << "3. Quit program\n";
    cin >> menu;

    do {
        switch (menu) {
        case 1:
            cout << "How many students are in your class?\n";
            cin >> number;
            for (count = 0; count < number; count++) {
                cout << "Please enter the name of the student:\n";
                cin >> name;
                outputFile << name << endl; // Write name to file
            }
            break;

        case 2:
            outputFile.close(); // Close the output file before reading
            readFile.open("LineUp.txt");
            if (!readFile) {
                cout << "Error opening file." << endl;
            }
            else {
                // Read names from the file into the vector
                while (getline(readFile, name)) {
                    names.push_back(name);
                }
                readFile.close();

                // Sort names alphabetically
                sort(names.begin(), names.end());

                // Display sorted names
                cout << "Names of students in alphabetical order:\n";
                for (const string& sortedName : names) {
                    cout << sortedName << endl;
                }
            }
            outputFile.open("LineUp.txt", ios::app); // Reopen for further entries
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }

        cout << "Choose what you would like to do:\n"
            << "1. Enter names of students\n"
            << "2. Display names of students\n"
            << "3. Quit program\n";
        cin >> menu;

    } while (menu != 3);

    outputFile.close(); // Close the output file before exiting
    return 0;
}
