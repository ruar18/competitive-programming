#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;

int adj[10000], vis[10000], n, x, y, orig;
bool f;

bool dfs(int s, int t){
    vis[s] = 1;
    if(adj[s] == t) f=1;
    if(f && adj[s]==orig) return 1;
    if(vis[adj[s]]) return 0;
    return dfs(adj[s], t);
}

int sep(int s, int t){
    if(t==s) return -1;
    return 1 + sep(adj[s], t);
}

int main() {

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        adj[x] = y;
    }
    while(1){
        scanf("%d%d", &x, &y);
        if(x==0&&y==0) break;
        memset(vis, 0, sizeof(vis));
        f=0;
        orig=x;
        if(dfs(x, y))
            printf("Yes %d\n", sep(x,y));
        else
            printf("No\n");
    }
    return 0;
}