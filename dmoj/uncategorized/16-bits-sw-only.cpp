#include <iostream>
#include <vector>
using namespace std;

vector<bool> ans(1000);
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long val1, val2, val3;
		cin >> val1 >> val2 >> val3;
		if (val1 * val2 == val3)
			ans[i] = 1;
		else
			ans[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		if (ans[i] == 1)
			cout << "POSSIBLE DOUBLE SIGMA" << '\n';
		else
			cout << "16 BIT S/W ONLY" << '\n';
	}
    return 0;
}