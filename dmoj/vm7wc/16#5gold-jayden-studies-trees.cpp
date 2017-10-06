#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, x, y, ranks[10001], q[10001], f,b, cur;
vector<int> adj[10001];

void bfs(int s){
    f=b=0;
    q[++b]=s;
    cur=s;
    ranks[s]=0;
    while(f!=b){
        cur=q[++f];
        for(int v : adj[cur]){
            if(ranks[v]==-1){
                ranks[v]=ranks[cur]+1;
                q[++b]=v;
            }
        }
    }

}
int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(ranks,-1,sizeof(ranks));
    bfs(1);
    memset(ranks,-1,sizeof(ranks));
    bfs(q[b]);
    printf("%d\n", ranks[q[b]]);
    return 0;
}