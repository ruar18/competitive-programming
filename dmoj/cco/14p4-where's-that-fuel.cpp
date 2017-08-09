#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


vector<pair<int, int>> fuels;
int main()
{

	int N, P;
	scanf("%i%i", &N, &P);
	int fuel = 0;
	int stars = 1;
	for (int i = 0; i < N; i++) {
		if (i == P - 1) {
			int value;
			scanf("%i", &value);
			fuel += value;
			scanf("%i", &value);
			continue;
		}
		int A, B;
		scanf("%i%i", &A, &B);
		fuels.push_back(make_pair(A,B));
	}

	sort(fuels.begin(), fuels.end());
	for (int i = 0; i < N - 1; i++) {
		if (fuel - fuels[i].second >= 0 && (fuels[i].first - fuels[i].second) >= 0) {
			fuel += (fuels[i].first - fuels[i].second);
			stars++;
			continue;
		}
	}

	printf("%i\n%i", fuel, stars);
    return 0;
}