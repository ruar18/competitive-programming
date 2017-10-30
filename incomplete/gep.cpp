#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, x, y, cnt;
ll ans;
bool state[21], adj[21][21];
ll fac[21] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000};
ll calculate(int n, int k){
    if(n==k) return 1;
    return fac[n] / (fac[k] * fac[n - k]);
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++){
        scanf("%d%d", &x, &y);
        adj[x][y] = adj[y][x] = 1;
    }

    for (int i = 1; i <= n; i++){
        if(state[i])
            continue;
        cnt = 0;
        for (int j = 1; j <= n; j++){
            if(adj[i][j])
                continue;
            cnt++;
            state[j] = 1;
        }
        // printf("cnt: %d\n", cnt);
        for (int k = 2; k <= cnt; k++){
            ans += calculate(cnt, k);
            // printf("%d choose %d: %d\n", cnt, k, calculate(cnt,k));
        }
    }
    // printf("ans so far: %d\n", ans);
    ans += n + 1;
    printf("%lld", ans);
    return 0;
}