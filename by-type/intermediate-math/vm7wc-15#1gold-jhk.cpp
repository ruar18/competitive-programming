#include <cstdio>
#include <cstring>
using namespace std;

int p[7002], dp[7002];

int min(int a, int b){
    return a < b? a:b;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 2; i <= n; i++){
        // If composite
        if(p[i])
            continue;
        dp[i] = 1;
        for(int j = i; j<=n; j++){
            dp[j] = min(dp[j], dp[j-i]+1);
            // If i is a factor
            if(j%i==0)
                p[j] = 1;
        }
    }

    int ans = 0;
    for(int i = 2; i <= n; i++){
        ans += dp[i] == k;
    }
    printf("%d\n", ans);
    return 0;
}
