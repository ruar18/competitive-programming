#include <bits/stdc++.h>
using namespace std;

char g[1001][1001];
int dis[1001][1001], dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int n, m;
pair<int, int> s, e;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> g[i][j];
			if(g[i][j]=='s') s = make_pair(i, j);
			if(g[i][j]=='e') e = make_pair(i, j);
		}
	}
	memset(dis, -1, sizeof(dis));
	queue<pair<int, int>> q;
	q.push(s);
	while(!q.empty()){
		int r = q.front().first, c = q.front().second;
		q.pop();
		if(r == e.first && c == e.second) break;
		for(int k = 0; k < 4; k++){
			int nr = r + dir[k][0], nc = c + dir[k][1];
			if(nr>=0 && nc>=0 && nr<n && nc<m && g[nr][nc]!='X' && dis[nr][nc]==-1){
				dis[nr][nc] = dis[r][c]+1;
				q.push(make_pair(nr, nc));
			}
		}
	}
	cout << dis[e.first][e.second];
	return 0;
}