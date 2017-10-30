#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int n, m, dist[1001], adj[1001][1001], x, y, w;

int main(){
	memset(dist, 0x3f, sizeof(dist));
	scan(n); scan(m);
	for(int i = 0; i < m; i++){
		scan(x); scan(y); scan(w);
		if(!adj[x][y] || w < adj[x][y])
			adj[x][y]=adj[y][x]=w;
	}

	priority_queue<pair<int,int>> q;
	q.push(make_pair(0, 1));
	dist[1]=0;
	while(!q.empty()){
		pair<int, int> cur = q.top()
;		q.pop();
		for(int i = 1; i <= n; i++){
			if(adj[cur.second][i] && dist[cur.second]+adj[cur.second][i] < dist[i]){
				dist[i] = dist[cur.second] + adj[cur.second][i];
				q.push(make_pair(-dist[i], i));
			}
		}
	}
	for(int i = 1; i <= n; i++)
{		if(dist[i]==0x3f3f3f3f) printf("-1\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
}