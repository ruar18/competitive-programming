#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

vector<pair<int, int>> points;
vector<double> distances;
vector<int> combos;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	// Number of circles and max jump distance
	int N, D;
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
		if (i > 0)
			distances.push_back(sqrt(pow((points[i].second - points[i - 1].second), 2) +
				pow((points[i].first - points[i - 1].first), 2)));
	}
	int count = 1;
	int maxCount = 1;
	for (int i = 0; i < distances.size(); i++) {
		if (distances[i] > D) {

			count = 0;
			continue;
		}
		count++;
		if (count > maxCount)
			maxCount = count;
	}

	cout << maxCount << endl;

    return 0;
}