#include <iostream>
using namespace std;

int r, c, ans, dir[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char g[100][100];

void dfs(int row, int col){
    if(row<0||col<0||row>=r||col>=c||g[row][col]=='X')
        return;
    g[row][col]='X';
    for(int i = 0; i < 4; i++){
        int nr=row+dir[i][0], nc=col+dir[i][1];
        if(nr>=0 && nc>=0 && nr<r && nc<c) dfs(nr, nc);
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> g[i][j];

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(g[i][j]=='.') { dfs(i, j); ans++;}
        }
    }
    cout << ans << '\n';
}
