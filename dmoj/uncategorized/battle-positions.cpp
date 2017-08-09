#include <vector>
#include <iostream>

using namespace std;

vector<int> A(100000);
vector<int> DA(100000);
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	// Number of stations, min troops at each station, num of waves
	int I, N, J;
	cin >> I >> N >> J;


	for (int i = 0; i < J; i++){
		// Lower and upper bounds, constant to increase range by
		int XI, XF, K;
		cin >> XI >> XF >> K;
		DA[XI - 1] += K;
		DA[XF] -= K;
	}
	A[0] = DA[0];

	// How many stations don't have the min num
	int count = 0;
	for (int i = 1; i < I; i++) {
		A[i] = A[i - 1] + DA[i];
	}
	for (int i = 0; i < I; i++) {
		if (A[i] < N)
			count++;
	}

	cout << count << endl;
    return 0;
}