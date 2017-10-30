#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#include <cstdio>
using namespace std;

int n, m, x, y, temp, par[21];
bool adj[21][21], vis[21], ans;

bool dfs(int s){
	if(vis[s]){
		temp = 1;
		int cur = par[s];
		while(cur!=s){
			temp++;
			cur = par[cur];
		}
		if(cur == 6) {
			ans = 1;
			return;
		}
	}


}

int main(){
	scan(n); scan(m);
	for(int i = 0; i < m ; i++){
		scan(x); scan(y);
		adj[x][y]=adj[y][x]=1;
	}
	par
	for(int i = 1; i <= n; i++){}
		if(!vis[i]){
			if(dfs(i)) {
				printf("YES"); return 0;
			}
		}
	}

	printf("NO");
	return 0;
}