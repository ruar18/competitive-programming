#include <bits/stdc++.h>
using namespace std;
int r, c, ans, dir[4][2]={{0,1}, {0,-1}, {-1,0}, {1,0}};
char g[36][51];
bool monk;
void dfs(int row, int col){
	if(row<0 || col<0 || row>=r || col>=c || g[row][col]=='#') return;
	if(g[row][col]=='M') {monk=1;}
	g[row][col]='#';
	for(int k=0; k<4; k++){
		int nr=row+dir[k][0], nc=col+dir[k][1];
		dfs(nr, nc);
	}
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> g[i][j];
		}
	}
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(g[i][j]=='.'||g[i][j]=='M'){
				dfs(i, j);
				if(monk) {ans++; monk=0;}
			}
		}
	}
	printf("%d", ans);
}