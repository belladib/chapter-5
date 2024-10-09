//this program will calculate the daily population increase and give you the total population at the end
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double start, total(0), days, count, increase;

	do
	{
		cout << "If you would like to calculate the daily population increase\n"
			<< "please enter the starting population of the organism\n"
			<< "It must be a value more than 1, if not, this message will pop up again\n";
		cin >> start;
	} while (start < 2);

	do
	{
		cout << "\nHow much would you like the population to increase? please enter a percentage in decimal form\n"
			<< "It must be a value more than 0 and cannot be a negative\n";
		cin >> increase;
	} while (increase <= 0);

	do
	{
		cout << "How many days would you like them to repopulate for?\n"
			<< "Please enter a value more than 0\n";
		cin >> days;
	} while (days < 1);

	for (count = 1; count <= days; count++)

	{
		cout << fixed << setprecision(0) << right;
		cout << "your population for day " << count << " is " << start << endl;
		start = (start * increase) + start;
		total += start;
	}
	cout << "\n the total population is " << total;

	return 0;


}