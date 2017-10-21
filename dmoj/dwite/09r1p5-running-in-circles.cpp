#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#include <cstdio>
#include <cstring>
using namespace std;

int vis[101], n, x, y, first, ans, parents[101];
bool g[101][101], stop;

void dfs(int s){
	// backtrack
	if(vis[s]==1){
		int cur = s;
		ans=0;
		while(1){
			cur = parents[cur];
			ans++;
			if(cur == s){
				break;
			}
		}
		stop=1;
		return;
	}
	vis[s]=1;
	for(int i = 1; i <= 100; i++){
		if(g[s][i]){
			parents[i] = s;
			dfs(i);
			if(stop) return;
		}
	}
	vis[s]=2;

}

int main(){
	for(int k = 0; k < 5; k++){
		scan(n);
		for(int i = 0; i < n; i++){
			scan(x); scan(y);
			if(i==0) first=x;
			g[x][y]=1;
		}
		parents[first]=0;
		dfs(first);
		printf("%d\n", ans);
		stop=0;
		memset(vis, 0, sizeof(vis));
		memset(g, 0, sizeof(g));
	}
	return 0;
}