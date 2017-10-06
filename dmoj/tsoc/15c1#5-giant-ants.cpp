#include <cstdio>
#include <cstring>
using namespace std;

bool adj[101][101], vis[101];
int n, m, w, x, y, curw, ants[101], q[101], f, b, dists[101];

void a_bfs(int disp){
    f=b=0;
    q[++b]=disp;
    vis[disp]=1;
    ants[disp]=0;
    while(f!=b){
        curw=q[++f];
        for(int i=1;i<=n;i++){
            if(adj[curw][i]&&!vis[i]&&ants[curw]+4<ants[i]){
                ants[i]=ants[curw]+4;
                vis[i]=1;
                q[++b]=i;
            }
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++){
        scanf("%d%d", &x, &y);
        adj[x][y]=1;
        adj[y][x]=1;
    }
    memset(ants, 0x3f, sizeof(ants));
    scanf("%d", &w);
    for(int i=0;i<w;i++){
        memset(vis, 0, sizeof(vis));
        scanf("%d", &curw);
        a_bfs(curw);
    }
    // their bfs
    f=b=0;
    memset(vis,0,sizeof(vis));
    q[++b]=1;
    vis[1]=1;
    dists[1]=0;
    while(f!=b && curw!=n){
        curw=q[++f];
        for(int i=0;i<=n;i++){
            if(adj[curw][i]&&!vis[i]&&dists[curw]+1<ants[i]){
                vis[i]=1;
                dists[i]=dists[curw]+1;
                q[++b]=i;
            }
        }
    }
    if(vis[n]) printf("%d\n", dists[n]);
    else printf("sacrifice bobhob314\n");
    return 0;
}