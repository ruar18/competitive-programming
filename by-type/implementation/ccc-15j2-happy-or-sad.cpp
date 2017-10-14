#include <iostream>

using namespace std;

char c[255];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
	cin.getline(c, 255);
	int s = 0, h = 0;
	for (int i = 0; c[i] != '\n' && i < 252; i++) {
		if (c[i] == ':' && c[i + 1] == '-' && c[i + 2] == '(')
			s++;
		else if (c[i] == ':' && c[i + 1] == '-' && c[i + 2] == ')')
			h++;
	}

	if (h == 0 && s == 0)
		cout << "none" << endl;
	else if (h == s)
		cout << "unsure" << endl;
	else if (h > s)
		cout << "happy" << endl;
	else
		cout << "sad" << endl;
    return 0;
}