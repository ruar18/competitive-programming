#include <iostream>
#include <string>
using namespace std;
int main()
{
	int b, f, l, t, c;
	b = f = l = t = c = 0;
	string parts;
	cin >> parts;
	for (int i = 0; i < parts.length(); i++) {
		if (parts[i] == 'B')
			b++;
		else if (parts[i] == 'F')
			f++;
		else if (parts[i] == 'L')
			l++;
		else if (parts[i] == 'T')
			t++;
		else
			c++;
	}
	if (b > 0 && f > 0 && l > 0 && t > 0 && c > 0)
		cout << "NO MISSING PARTS" << endl;
	if (b == 0)
		cout << "B" << endl;
	if (f == 0)
		cout << "F" << endl;
	if (l == 0)
		cout << "L" << endl;
	if (t == 0)
		cout << "T" << endl;
	if (c == 0)
		cout << "C" << endl;
    return 0;
}