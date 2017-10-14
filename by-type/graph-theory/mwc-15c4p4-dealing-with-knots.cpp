#include <cstdio>
using namespace std;

bool adj[1001][1001];
int n, x, y, q[1001], f, b, cur, vis[1001];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        adj[x][y]=1;
    }
    scanf("%d%d", &x, &y);
    f=b=0;
    q[++b]=x;
    cur = x;
    vis[x]=1;
    while(f!=b){
        cur=q[++f];
        for(int i = 1; i<=1000; i++){
            if(adj[cur][i]&&!vis[i]){
                vis[i]=1;
                q[++b]=i;
            }
        }
    }
    if(vis[y]) printf("Tangled\n");
    else printf("Not Tangled\n");
    return 0;
}