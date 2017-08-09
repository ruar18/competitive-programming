#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> orig, sorted;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		orig.push_back(val);
		sorted.push_back(val);
	}

	sort(sorted.rbegin(), sorted.rend());

	int count = 0;
	for (int i = 0; i < N; i++) {
		if (count == K) break;
		if (sorted[i] > orig[i]) {
			int swap;
			swap = orig[i];
			orig[find(orig.begin(), orig.end(), sorted[i]) - orig.begin()] = swap;
			orig[i] = sorted[i];
			count++;
			continue;
		}
		else
			continue;
	}

	for (int i = 0; i < N; i++)
		cout << orig[i] << " ";
    return 0;
}