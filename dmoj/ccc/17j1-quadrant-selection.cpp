#include <iostream>

using namespace std;

int main()
{
	int X, Y;
	cin >> X >> Y;

	if (X > 0 && Y > 0)
		cout << 1 << endl;
	else if (X < 0 && Y > 0)
		cout << 2 << endl;
	else if (X < 0 && Y < 0)
		cout << 3 << endl;
	else
		cout << 4 << endl;

    return 0;
}