#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, x, y, ans, dist[101];
bool vis[101], g[101][101];

int main(){
	for(int a = 0; a < 5; a++){
		scan(n);
		ans=0;
		queue<int> q;
		for(int i = 0; i < n; i++){
			scan(x); scan(y);
			g[x][y]=1;
			g[y][x]=1;
		}
		q.push(1);
		vis[1]=1;
		dist[1]=0;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int i = 1; i <= 100; i++){
				if(g[cur][i]&&!vis[i]){
					dist[i]=dist[cur]+1;
					vis[i]=1;
					q.push(i);
				}
			}
		}
		for(int i = 1; i <= 100; i++){
			for(int j = i+1; j <= 100; j++){
				if(g[i][j]&&dist[i]==dist[j]) ans++;
			}
		}
		printf("%d\n", ans);
		memset(vis, 0, sizeof(vis));
		memset(g, 0, sizeof(g));
	}
	return 0;
}