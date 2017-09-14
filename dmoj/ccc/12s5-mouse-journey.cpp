#include <iostream>
#include <algorithm>
using namespace std;

int dp[26][26], r, c, k, x, y;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> k;
    while(k--)
    {
        cin >> x >> y;
        dp[x][y]=-1;
    }
    dp[1][1] = 1;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            if(dp[i][j] != -1)
                dp[i][j] += max(dp[i-1][j],0) + max(dp[i][j-1], 0);
    cout << dp[r][c] << '\n';
    return 0;
}