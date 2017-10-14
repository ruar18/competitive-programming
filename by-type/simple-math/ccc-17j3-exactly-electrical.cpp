#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a, b, c, d, t;
	cin >> a >> b >> c >> d >> t;
	int diff = abs(a - c) + abs(b - d);
	if (abs(diff) > t) {
		cout << 'N' << endl;
		return 0;
	}
	diff -= t;
	if (diff % 2 == 0)
		cout << 'Y' << endl;
	else
		cout << 'N' << endl;
    return 0;
}