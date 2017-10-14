#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> times;
int main()
{


	int N;
	scanf("%i", &N);
	for (int i = 0; i < N; i++) {
		int value, seconds;
		scanf("%i%i", &value, &seconds);
		value *= 60;
		value += seconds;
		times.push_back(value);
	}

	sort(times.begin(), times.end());
	int X, Y;
	cin >> X >> Y;
	X *= 60;
	X += Y;

	for (int i = 0; i < N; i++) {
		if (i != 0)
			times[i] += times[i - 1];
		if (times[i] > X) {
			printf("%i", i);
			return 0;
		}
	}
	printf("%i", N);
    return 0;
}