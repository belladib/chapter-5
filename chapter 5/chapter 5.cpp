#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string file, town;
    int interval, amt, start, pop;

    cout << "To show a population bar chart please enter the yearly interval rate\n";
    cin >> interval;
    if (interval < 1)
        return 1;

    cout << "What is the starting year\n";
    cin >> start;
    if (start < 1)
        return 1;

    cout << "How many intervals would you like there to be\n";
    cin >> amt;
    if (amt < 1)
        return 1;

    cout << "What is the name of the town?\n";
    cin >> town;

    cout << "What would you like to name the file\n";
    cin >> file;

    ofstream writefile;
    writefile.open(file);

    if (writefile)
    {
        for (int count = 0; count < amt; count++)
        {
            cout << "\nWhat is the population of the town for year " << start << endl;
            cin >> pop;

            int stars = pop / 1000;

            writefile << start << " " << stars << endl; // Write year and stars
            start += interval;
        }
    }
    else
    {
        cout << "Error opening file";
        return 1;
    }
    writefile.close(); // Close the write file

    ifstream readfile;
    readfile.open(file);

    if (readfile)
    {
        cout << "Opening file " << file << endl;
        cout << town << " Population Growth:\n"
            << "Each * represents 1,000 people\n";

        int stars;
        while (readfile >> start >> stars) // Read year and stars
        {
            cout << start << " : ";
            for (int count = 0; count < stars; count++)
                cout << "*";
            cout << endl;
        }
    }
    else
    {
        cout << "Error opening file";
        return 1;
    }

    readfile.close();
    return 0;
}
