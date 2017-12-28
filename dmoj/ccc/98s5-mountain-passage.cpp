#include <bits/stdc++.h>
using namespace std;
int n, adj[25][25], dis[25][25], t, ans, d[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--){
        memset(dis, -1, sizeof(dis));
        cin >> n;
        for(int i = 0; i < n ;i++){
            for(int j = 0; j < n; j++){
                cin >> adj[i][j];
            }
        }
        int b=adj[0][0];
        queue<int> q;
        q.push(0); q.push(0);
        dis[0][0]=0;
        while(!q.empty()){
            int x=q.front(); q.pop();
            int y=q.front(); q.pop();
            for(int k = 0; k<4; k++){
                int nx=x+d[k][0], ny=y+d[k][1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && dis[nx][ny]==-1 && abs(adj[x][y]-adj[nx][ny])<=2){
                    if(adj[x][y]>b||adj[nx][ny]>b) dis[nx][ny]=dis[x][y]+1;
                    else dis[nx][ny]=dis[x][y];
                    q.push(nx); q.push(ny);
                }
            }
        }
        if(dis[n-1][n-1]==-1) cout << "CANNOT MAKE THE TRIP\n\n";
        else cout << dis[n-1][n-1] << "\n\n";
	}
	return 0;
}
