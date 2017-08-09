#include <vector>
#include <iostream>

using namespace std;


// Vector that contains running totals
vector<int> PFS(500000);
// Answers to queries
vector<int> solutions(500000);
int main()
{
	// Fast input
	cin.sync_with_stdio(0);
	cin.tie(0);

	// N is the number of ratings, Q is the number of queries
	int N, Q;
	cin >> N >> Q;
	// Read in values to PFS, keep running sum
	for (int i = 0; i < N; i++) {
		if (i != 0) {
			cin >> PFS[i];
			PFS[i] += PFS[i - 1];
		}
		else {
			cin >> PFS[i];
		}
	}

	// Read in queries and output sums
	for (int i = 0; i < Q; i++) {
		// Read in lower and top bounds
		int a, b;
		cin >> a >> b;
		// Calculate the ratings of the episodes skipped
		if (a - 2 >= 0)
			solutions[i] = PFS[N - 1] - PFS[b - 1] + PFS[a - 2];
		else
			solutions[i] = PFS[N - 1] - PFS[b - 1];
	}

	for (int i = 0; i < Q; i++) {
		cout << solutions[i] << endl;
	}
    return 0;
}