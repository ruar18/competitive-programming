#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, unsigned long long> cubes;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M, Q;
	cin >> N >> M >> Q;
	int val;
	cin >> val;
	unsigned long long prev = val;
	cubes.insert(make_pair(val, val));
	for (int i = 1; i < N; i++)
	{
		cin >> val;
		cubes.insert(make_pair(val, val + prev));
		prev += val;
	}

	for(int i = 0; i < Q; i++)
	{
		int a, b;
		cin >> a >> b;
		if ((cubes.find(b)->second - cubes.find(a)->second + a)/2.0 >= M)
			cout << "Enough\n";
		else
			cout << "Not enough\n";
	}
    return 0;
}