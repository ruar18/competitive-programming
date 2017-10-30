#include <bits/stdc++.h>
using namespace std;
int r, c, x, y, sx, sy, ox, oy, t, dist[1001][1001], d[4][2]={{0,1},{0,-1},{1,0},{-1,0}}, mindist=123456789;
queue<int> q;
char grid[1001][1001];
int main(){
    memset(dist,-1,sizeof(dist));
    scanf("%d%d%d%d%d%d", &r, &c, &sx, &sy, &ox, &oy);
    if(sx==ox && sy==oy){ printf("0"); return 0; }
    q.push(sx); q.push(sy);
    dist[sx][sy]=0;
    for(int i =0; i <r;i++){
        for(int j=0;j<c;j++){
            scanf(" %c", &grid[i][j]);
        }
    }
    
    scanf("%d", &t);
    for(int i = 0;i<t;i++){
        scanf("%d%d", &x, &y);
        if(x==sx && y==sy) mindist=0;
        grid[x][y]='t';
    }
    grid[ox][oy]='e';
    while(!q.empty()){
        int cx=q.front(); q.pop();
        int cy=q.front(); q.pop();
        for(int k=0;k<4;k++){
            int nx=cx+d[k][0], ny=cy+d[k][1];
            if(nx>=0 && nx<r && ny>=0 && ny<c && grid[nx][ny]!='X' && dist[nx][ny]==-1){
                dist[nx][ny] = dist[cx][cy]+1;
                if(grid[nx][ny]=='e'){printf("%d", max(dist[nx][ny]-mindist, 0)); return 0;}
                if(grid[nx][ny]=='t' && mindist==123456789) mindist=dist[nx][ny];
                q.push(nx); q.push(ny);
            }
        }
    }
    return 0;
}