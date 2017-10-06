#include <cstdio>
#include <utility>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int n, h, grid[1501][1501], f, b, x, y;
bool vis[1501][1501];
pair<int, int> q[2250001];

int main() {
    scanf("%d%d", &n, &h);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &grid[i][j]);
        }
    }
    pair<int, int> cur = {1,1};
    vis[1][1] = 1;
    q[++b] = cur;
    while(f!=b){
        cur = q[++f];
        x = cur.first, y = cur.second;
        if(x == n && y == n) break;
        if(y+1 <= n && !vis[x][y+1] && abs(grid[x][y+1]-grid[x][y]) <= h){
            q[++b] = make_pair(x, y+1);
            vis[x][y+1] = 1;
        }
        if(y-1>=1 && !vis[x][y-1] && abs(grid[x][y-1] - grid[x][y]) <= h){
            q[++b] = make_pair(x, y-1);
            vis[x][y-1] = 1;
        }
        if(x+1 <= n && !vis[x+1][y] && abs(grid[x+1][y]-grid[x][y]) <= h){
            q[++b] = make_pair(x+1, y);
            vis[x+1][y] = 1;
        }
        if(x-1>=1 && !vis[x-1][y] && abs(grid[x-1][y] - grid[x][y]) <= h){
            q[++b] = make_pair(x-1, y);
            vis[x-1][y] = 1;
        }
    }
    if(vis[n][n]) printf("yes\n");
    else printf("no\n");
    return 0;
}