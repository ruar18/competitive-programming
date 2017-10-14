#include <cstdio>
#include <algorithm>
using namespace std;

int dp[200001];
int main()
{ 
	int n, x, y, z;
	scanf("%d%d%d%d", &n, &x, &y, &z);
	for (int i = 0; i <= n; i++) {
		if (dp[i] != 0 || i == 0) {
			dp[i + x] = max(dp[i+x], dp[i]+1);
			dp[i + y] = max(dp[i + y], dp[i] + 1);
			dp[i + z] = max(dp[i + z], dp[i] + 1);
		}
	}
	printf("%d\n", dp[n]);
    return 0;
}