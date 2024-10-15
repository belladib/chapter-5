

#include <iostream>
using namespace std;

int main()
{
    // Display Pattern A
    cout << "Pattern A\n";
    for (int count = 1; count <= 10; count++) {
        for (int count1 = 1; count1 <= count; count1++) {
            cout << "+";
        }
        cout << endl;
    }

    // Display Pattern B
    cout << "\nPattern B\n";
    for (int count = 10; count >= 1; count--) {
        for (int count1 = 1; count1 <= count; count1++) {
            cout << "+";
        }
        cout << endl;
    }

    return 0;
}





