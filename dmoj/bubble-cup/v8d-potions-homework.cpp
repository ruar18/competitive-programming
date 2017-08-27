include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int a[100000];
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	unsigned long long sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum += (a[i] % 10007 * a[n - i - 1] % 10007) % 10007;
		sum %= 10007;
	}
	cout << sum << '\n';
    return 0;
}