#include <cstdio>
#include <vector>
using namespace std;

int n, m, x, y, vis[10001];
vector<int> adj[10001];
bool cycle;

void dfs(int s){
    vis[s]=1;
    for(int v : adj[s]){
        if(vis[v]==1) {cycle=1;return;}
        if(vis[v]==0) dfs(v);
    }
    vis[s]=2;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            if(cycle){
                printf("N");
                return 0;
            }
        }
    }
    printf("Y");
    return 0;
}