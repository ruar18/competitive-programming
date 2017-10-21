#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[5281], clubs[32], d, n;

int main(){
    scan(d); scan(n);
    for(int i = 0; i < n; i++) scan(clubs[i]);
    memset(dp, 0x3f, sizeof(dp));
    dp[0]=0;
    // printf("current value: %d\n", dp[d]);
    for(int i = 0; i <= d; i++){
        for(int j = 0; j < n; j++){
            if(i+clubs[j]<=d) dp[i+clubs[j]] = min(dp[i+clubs[j]], dp[i]+1);
        }
    }
    // for(int i = 1; i <= d; i++) printf("%d ", dp[i]);
    if(dp[d]>=d) printf("Roberta acknowledges defeat.");
    else printf("Roberta wins in %d strokes.", dp[d]);
    // printf("dp[d]: %d", 0x3f3f3f3f);
    return 0;
}
