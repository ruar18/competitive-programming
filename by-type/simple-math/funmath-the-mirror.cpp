#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int a, b;
	a = b = 0;
	int count = 0;
	int factors = 0;


	while (N--)
	{
		count = factors = 0;
		cin >> a >> b;
		for (int i = a; i < b; i++) {
			factors = 0;
			for (int j = 2; j < i; j++) {
				if (i % j == 0) factors++;
			}
			if (factors == 0 && i != 1 || i == 2) count++;
		}
		ans.push_back(count);
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';

	return 0;
}