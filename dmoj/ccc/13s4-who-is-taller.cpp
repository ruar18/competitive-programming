#include <cstdio>
#include <utility>
#include <cstring>
#include <vector>
using namespace std;

vector<int> adj[1000001];
bool vis[1000001];
int n, m, x, y, q[1000001], cur;

bool bfs(int s, int t){
    memset(vis, 0, sizeof(vis));
    int f=0, b=0;
    q[++b]=s;
    vis[s]=1;
    while(f!=b){
        cur = q[++f];
        if(cur == t) return 1;
        for(int i = 0; i < adj[cur].size(); i++){
            if(!vis[adj[cur][i]]){
                vis[adj[cur][i]]=1;
                q[++b] = adj[cur][i];
            }
        }
    }
    return vis[t];
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i =0 ; i < m; i++){
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
    }
    scanf("%d%d", &x, &y);
    bool f1=0, f2=0;
    f1 = bfs(x,y);
    f2 = bfs(y,x);
    if(f1 == f2) printf("unknown\n");
    else if(f1) printf("yes\n");
    else printf("no\n");
    return 0;
}
