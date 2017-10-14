#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> PFS;
vector<int> solutions;
int main()
{
	// Fast input
	cin.sync_with_stdio(0);
	cin.tie(0);

	// F is the number of floors, R is the number of apartments per floor
	int F, R;
	cin >> F >> R;
	for (int i = 0; i < F; i++) {
		vector<int> PFSRow;
		for (int j = 0; j < R; j++) {
			// Number of cd's in the apartment
			int C;
			cin >> C;
			PFSRow.push_back(C);
		}
		PFS.push_back(PFSRow);
	}

	// Calculate the prefix sums
	for (int i = 0; i < F; i++) {
		for (int j = 1; j < R; j++) {
			PFS[i][j] += PFS[i][j - 1];
		}
	}

	// Number of queries
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		// Lower and upper bounds inclusive, floor
		int a, b, c;
		cin >> a >> b >> c;
		if (a > 1)
			solutions.push_back(PFS[c-1][b - 1] - PFS[c-1][a - 2]);
		else
			solutions.push_back(PFS[c-1][b - 1]);
	}

	for (int i = 0; i < Q; i++) {
		cout << solutions[i] << endl;
	}
    return 0;
}