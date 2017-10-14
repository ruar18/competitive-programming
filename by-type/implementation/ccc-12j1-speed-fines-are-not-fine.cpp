#include <iostream>
using namespace std;
int main()
{
	int lim, speed;
	cin >> lim >> speed;
	int diff = speed - lim, fine = 0;
	if (diff < 1) {
		cout << "Congratulations, you are within the speed limit!";
		return 0;
	}
	else if (diff >= 1 && diff <= 20)
		fine = 100;
	else if (diff >= 21 && diff <= 30)
		fine = 270;
	else
		fine = 500;
	cout << "You are speeding and your fine is $" << fine << "." << endl;
    return 0;
}