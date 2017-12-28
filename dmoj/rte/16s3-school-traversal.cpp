#include <bits/stdc++.h>
using namespace std;

int dis[6000][6000], n, a, b, w, q;
vector<pair<int,int> > adj[6000];

int main(){
	scanf("%d",&n);
	for(int i=1; i<n;i++){
		scanf("%d%d%d", &a,&b,&w);
		adj[a].push_back(make_pair(b,w)); adj[b].push_back(make_pair(a,w));
	}
	for(int i = 0; i < n; i++){
		bool vis[6000]={0};
		queue<int> que;
		que.push(i);
		vis[i]=1;
		while(!que.empty()){
			int cur=que.front(); que.pop();
			for(pair<int,int> p:adj[cur]){
				if(!vis[p.first]){
					dis[i][p.first]=dis[i][cur]+p.second;
					vis[p.first]=1;
					que.push(p.first);
				}
			}
		}
	}
  
	scanf("%d", &q);
	while(q--){
		scanf("%d%d",&a,&b);
		printf("%lld\n", dis[a][b]);
	}
	return 0;
}
