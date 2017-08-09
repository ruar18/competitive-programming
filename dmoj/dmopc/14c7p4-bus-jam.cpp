#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> times;
int main()
{
	// Number of buses, duration of one break, maximum headway
	int N, M, H;
	cin >> N >> M >> H;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		times.push_back(val);
	}

	sort(times.rbegin(), times.rend());
	int count = 0;
	for (int i = 0; i < N - 1; i++) {
		if (times[i] - times[i + 1] > H) {
			int val = ceil(((times[i] - times[i + 1]) - H) / 2.0);
			times[i + 1] += val * M;
			count += val;
		}
		else
			continue;
	}

	cout << count;
    return 0;
}