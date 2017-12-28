#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
bool adj[21][21];
long long ans;
vector<int> cur;
void go(int s){
    cur.push_back(s);
    if(cur.size()>1){
        for(int v:cur)
            if(adj[s][v]) return;
        ans++;
    }
    for(int i = s+1; i<= n; i++){
        if(!adj[s][i]){
            go(i);
            cur.pop_back();
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        adj[a][b]=adj[b][a]=1;
    }
    ans=n+1;
    for(int i = 1; i <=n; i++){
        go(i);
        cur.pop_back();
    }
    printf("%lld", ans);
	return 0;
}
