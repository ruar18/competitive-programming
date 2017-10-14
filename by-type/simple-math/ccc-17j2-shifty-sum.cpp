#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	long long sum = 0;
	for (int i = 0; i <= K; i++) {
		sum += N * pow(10, i);
	}

	cout << sum << endl;
    return 0;
}