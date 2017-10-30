#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int r, c, px, py, bx, by, dist[1001][1001], d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char grid[31][31];
queue<pii> q;
bool legal(int x, int y, int x2, int y2){
    if(x<0||y<0||x>=r||y>=c||x2<0||y2<0||x2>=r||y2>=c||dist[x*30+y][x2*30+y2]>-1||grid[x][y]=='#'||grid[x2][y2]=='#') return 0;
    return 1;
}
int main(){
    scanf("%d%d", &r, &c);
    for(int i = 0; i< r; i++){
        for(int j = 0; j < c; j++){
            scanf(" %c", &grid[i][j]);
            if(grid[i][j]=='P'){px=i; py=j;}
            if(grid[i][j]=='B'){bx=i; by=j;}
        }
    }
    memset(dist, -1, sizeof(dist));
    dist[px*30+py][bx*30+by]=0;
    q.push({px,py}); q.push({bx,by});
    while(!q.empty()){
        int cpx=q.front().first, cpy=q.front().second; q.pop();
        int cbx=q.front().first, cby=q.front().second; q.pop();
        for(int k=0; k<4; k++){
            int npx=cpx+d[k][0], npy=cpy+d[k][1];
            if(legal(npx, npy, cbx, cby)){
                if(npx==cbx && npy==cby){
                    int nbx=cbx+d[k][0], nby=cby+d[k][1];
                    if(legal(npx, npy, nbx, nby)){
                        dist[npx*30+npy][nbx*30+nby] = dist[cpx*30+cpy][cbx*30+cby]+1;
                        if(grid[nbx][nby]=='X'){printf("%d", dist[npx*30+npy][nbx*30+nby]); return 0;}
                        q.push({npx,npy}); q.push({nbx,nby});
                    }
                }
                else{
                    dist[npx*30+npy][cbx*30+cby] = dist[cpx*30+cpy][cbx*30+cby]+1;
                    q.push({npx, npy}); q.push({cbx, cby});
                }
            }
        }
    }
    printf("-1");
    return 0;
}