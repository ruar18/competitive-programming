#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> cards;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	if(N == 1){
	    int val;
	    cin >> val;
	    cout << val;
	    return 0;
	}
	int negatives = 0;
	int zeroes = 0;
	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		if (value < 0) negatives++;
		else if (value == 0) zeroes++;
		cards.push_back(value);
	}

	sort(cards.begin(), cards.end());

	int ans = 1;
	bool includeNeg = negatives % 2 == 0;

	if (N == 1 && negatives == 1) ans = cards[0];
	else if (zeroes + negatives == N) ans = 0;
	else {
		for (int i = 0; i < N; i++){
			if (cards[i] == 0) continue;
			else if (cards[i] < 0 && includeNeg) {
				ans *= cards[i];
				continue;
			}
			else if (cards[i] < 0 && negatives != 1) {
				ans *= cards[i];
				negatives--;
				continue;
			}
			else if (cards[i] > 0) {
				ans *= cards[i];
				continue;
			}
		}
	}

	cout << ans;
    return 0;
}