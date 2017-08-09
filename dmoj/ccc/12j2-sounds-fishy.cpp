#include <iostream>

using namespace std;

int main()
{
	int curr = 0, prev = 0, negs = 0, pos = 0, same = 0;
	cin >> prev;
	for (int i = 1; i < 4; i++) {
		cin >> curr;
		if (prev == curr)
			same++;
		if (prev - curr > 0)
			pos++;
		else if (prev - curr < 0) {
			negs++;
		}
		prev = curr;
	}
	if (same == 3)
		cout << "Fish At Constant Depth" << endl;
	else if (pos == 3)
		cout << "Fish Diving" << endl;
	else if (negs == 3)
		cout << "Fish Rising" << endl;
	else
		cout << "No Fish" << endl;

	return 0;
}