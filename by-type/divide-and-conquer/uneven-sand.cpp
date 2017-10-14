#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	long long high = 2 * pow(10, 9), low = 1, mid = (high+low)/2;
	cout << mid << endl;
	string res;
	cin >> res;
	while (res != "OK") {
		if (res == "SINKS")
			low = mid + 1;
		else if (res == "FLOATS")
			high = mid - 1;
		mid = (high + low) / 2;
		cout << mid << endl;
		cin >> res;
	}
    return 0;
}