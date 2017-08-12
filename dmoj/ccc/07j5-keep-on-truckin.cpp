#include <cstdio>
#include <algorithm>
using namespace std;

int m[34] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000}, dp[34];
int main()
{
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    for(int i = 14; i < 14 + n; i++)
        scanf("%d", &m[i]);
    if(n>0)
        sort(m, m+14+n);
    dp[0] = 1;
    n += 14;
    for(int i=0; i < n-1; i++){
        if(!dp[i]) continue;
        for(int j = i+1; j < n; j++){
            if(m[j] - m[i] > b)
                break;
            else if(m[j] - m[i] >= a)
                dp[j] += dp[i];
        }
    }
    printf("%d\n", dp[n-1]);
    return 0;
}
