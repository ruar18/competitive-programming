#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n, e = 0, p = 0;
	cin >> n;
	double ans = 1;
	while (n--) {
		cin >> e >> p;
		ans *= (1.0*(p-e) / p);
	}
	cout << ans << endl;
    return 0;
}