#include <bits/stdc++.h>
using namespace std;
int n, dp[10000], x, y;
vector<int> adj[10000];
int main(){
	scanf("%d%d%d",&n, &x, &y);
	while(x!=0 || y!=0){
        adj[x].push_back(y);
        scanf("%d%d", &x, &y);
	}
	dp[1]=1;
	for(int i = 1; i < n; i++){
        for(int v:adj[i]) dp[v]+=dp[i];
	}
	printf("%d", dp[n]);
	return 0;
}
