#include <bits/stdc++.h>
using namespace std;

int t, l, w, dist[50][50], cx, cy, wx, wy, d[4][2]={{0,1}, {0,-1}, {1,0}, {-1, 0}};
char grid[50][50];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> l >> w;
        memset(dist, -1, sizeof(dist));
        for(int i = 0; i < w; i++){
            for(int j = 0; j < l; j++){
                cin>>grid[i][j];
                if(grid[i][j]=='C'){cx=i; cy=j;}
                if(grid[i][j]=='W'){wx=i; wy=j;}
            }
        }
        queue<int> q;
        q.push(cx); q.push(cy);
        dist[cx][cy]=0;
        while(!q.empty()){
            int curx=q.front(); q.pop();
            int cury=q.front(); q.pop();
            for(int k=0; k<4;k++){
                int nx=curx+d[k][0], ny=cury+d[k][1];
                if(nx>=0 && nx<w && ny>=0 && ny<l && (grid[nx][ny]=='O'||grid[nx][ny]=='W')  && dist[nx][ny]==-1){
                    dist[nx][ny] = dist[curx][cury]+1;
                    q.push(nx); q.push(ny);
                }
            }
        }
        if(dist[wx][wy]>=60||dist[wx][wy]==-1) cout << "#notworth\n";
        else cout << dist[wx][wy] << '\n';
        
        memset(grid, 0, sizeof(grid));
    }

    return 0;
}