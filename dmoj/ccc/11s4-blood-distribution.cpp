#include <vector>
#include <iostream>

using namespace std;

vector<int> units(8), reqs(8);

int check(int reqI, int unitI) {
	int origin = reqs[reqI];
	if (reqs[reqI] == 0) return 0;
	else if (reqs[reqI] >= units[unitI]) {
		reqs[reqI] -= units[unitI];
		units[unitI] = 0;
	}
	else {
		units[unitI] -= reqs[reqI];
		reqs[reqI] = 0;
	}
	return origin - reqs[reqI];
}

int main()
{
	for (int i = 0; i < 16; i++) {
		if (i < 8)
			scanf("%i", &units[i]);
		else
			scanf("%i", &reqs[i - 8]);
	}

	int count = 0;
	for (int i = 0; i < 8; i++) {
		count += check(i, i);
		if (i == 0) continue;
		if (i % 2 != 0 && i != 7)
		{
			count += check(i, i - 1);
			if (i == 1) continue;
			else if (reqs[i] > 0)
				count += check(i, 1);
			if (reqs[i] > 0)
				count += check(i, 0);
		}
		else if(i != 6 && i != 7) {
			count += check(i, 0);
			continue;
		}

		else if (i == 7) {
			count += check(i, 0) + check(i, 1) + check(i, 2);
			if (reqs[7] > 0)
				count += check(i, 3) + check(i, 4) + check(i, 5) + check(i, 6);
		}
		else {
			count += check(i, 4);
				count += check(i, 2);
			if (reqs[i] > 0)
				count += check(i, 0);
		}
	}
	cout << count;
    return 0;
}