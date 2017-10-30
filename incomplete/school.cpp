#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
vector<int> adj[21], cycle;
bool vis[21], ans;

void dfs(int s){
	cycle.push_back(s);
	vis[s]=1;
	for(int v:adj[s]){
		if(v!=s && !vis[v]){
			dfs(v);
			if(ans==1) return;
		}
		if(vis[v]){
			if(cycle.size()==6 && v==cycle[0]) {ans=1; return;}
		}
	}
	cycle.pop_back();
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m ;i++){
		scanf("%d%d", &u, &v);
		adj[u].push_back(v); adj[v].push_back(u);
	}
	dfs(1);
	if(ans) printf("YES");
	else printf("NO");
	return 0;
}
