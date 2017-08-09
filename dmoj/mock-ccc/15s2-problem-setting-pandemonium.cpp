#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> probs(100000);
int N;
int main()
{
	scanf("%i", &N);
	for (int i = 0; i < N; i++) {
		scanf("%i", &probs[i]);
	}

	sort(probs.rbegin(), probs.rend());

	int ans = 0;
	int maxChain = 1;
	for (int i = 0; i < N; i++) {
		if (probs[i] == probs[i + 1])	maxChain++;
		else {
			if (ans <= maxChain)
				ans = maxChain;
			maxChain = 1;
		}
	}

	printf("%i", ans);
    return 0;
}