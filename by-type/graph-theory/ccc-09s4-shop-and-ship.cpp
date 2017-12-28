#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int n, t, x, y, c, k, d, ps[5002];
int adj[5002][5002];
long long dis[5002];
bool vis[5002];
int main(){
    memset(dis, 0x3f, sizeof(dis));
    memset(ps, -1, sizeof(ps));
    scan(n); scan(t);
    while(t--){
        scan(x); scan(y); scan(c);
        adj[x][y]=adj[y][x] = c;
    }
    scan(k);
    while(k--){
        scan(x); scan(y);
        ps[x]=y;
    }
    scan(d);
    dis[d]=0;
    for(int k = 1; k<=n; k++){
        int cur=0;
        for(int i = 1; i <= n; i++){
            if(!vis[i] && dis[i]<dis[cur]) cur=i;
        }
        vis[cur]=1;
        for(int i = 1; i <= n; i++){
            if(!adj[cur][i]||vis[i]) continue;
            long long newDist = dis[cur] + adj[cur][i];
            if(newDist < dis[i]){
                dis[i] = newDist;
            }
        }
    }
    long long ans=pow(2, 62);
    for(int i = 1; i <= n; i++){
        if(ps[i]>=0){
            if(ps[i]+dis[i]<ans) ans=ps[i]+dis[i];
        }
    }
    printf("%lld", ans);
    return 0;
}
