#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int cont = 0, tot = 0, current = 0;
	char input[1000];
	cin.getline(input, 1001);
	for (int i = 0; i < 1000; i++) {
		char cur = input[i];
		if (cur == 'L') {
			current++;
			tot++;
			continue;
		}
		if (cur == ' ') {
			continue;
		}

		else {
			if (current > cont)
				cont = current;
			current = 0;
		}

	}
	cout << tot << " " << cont;
	return 0;
}