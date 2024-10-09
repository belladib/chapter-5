//for sorting names
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // For sorting
using namespace std;

int main()
{
    string name;
    int menu, count, number;
    ofstream outputFile;
    ifstream readFile;
    vector<string> names; // Vector to store names

    outputFile.open("LineUp.txt", ios::app); // Open in append mode

    do
    {
        cout << "\nChoose what you would like to do:\n"
            << "1. Enter names of students\n"
            << "2. Display names of students\n"
            << "3. Quit program\n";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "How many students are in your class? ";
            cin >> number;

            // Validate the number of students
            if (number < 1) {
                cout << "Please enter a valid number of students.\n";
                break;
            }

            for (count = 0; count < number; count++)
            {
                cout << "Please enter the name of student " << (count + 1) << ": ";
                cin >> name;
                outputFile << name << endl; // Write the name to the file
                names.push_back(name); // Store the name in the vector
            }
            break;

        case 2:
            outputFile.close(); // Close the output file before reading
            readFile.open("LineUp.txt");

            // Check if the file opened successfully
            if (!readFile) {
                cout << "Error opening file.\n";
                return 1;
            }

            // Clear the vector and read names from the file
            names.clear();
            while (getline(readFile, name))
                names.push_back(name);

            readFile.close(); // Close the input file
            outputFile.open("LineUp.txt"); // Reopen output file for further writing

            // Sort the names alphabetically
            sort(names.begin(), names.end());

            // Display sorted names
            cout << "Names of students (in alphabetical order):\n";
            for (const auto& n : names)
                cout << n << endl;
           
            break;

        case 3:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (menu != 3);

    outputFile.close(); // Close the output file before exiting
    return 0;
}
