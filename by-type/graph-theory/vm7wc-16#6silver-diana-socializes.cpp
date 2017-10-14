#include <iostream>
#include <set>
using namespace std;

int n, m, c=1, maxR=0, maxC=0;
char g[100][100];
int info[100][100], dir[8]={1, 0, 0, 1, -1, 0, 0, -1};
set<int> maxS;

void dfs(int r, int c, int num){
    if(r < 0 || c < 0 || r >= n || c >= m || g[r][c]=='X' || info[r][c]!=0) return;
    info[r][c]=num;
    for(int i = 0; i < 7; i+=2) dfs(r+dir[i], c+dir[i+1], num);
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j=0;j<m;j++)
            cin >> g[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(g[i][j]=='.' && info[i][j]==0)
                dfs(i, j, c++);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j]=='X'){
                set<int> surr;
                for(int k = 0; k < 7; k+=2){
                    if(i+dir[k] >= 0 && j+dir[k+1] >= 0 && i+dir[k] < n && j+dir[k+1] < m && g[i+dir[k]][j+dir[k+1]]!='X') surr.insert(info[i+dir[k]][j+dir[k+1]]);
                }
                if(surr.size() > maxS.size()) maxR=i, maxC=j, maxS=surr;
            }
        }
    }
    if(maxS.size()<=1){
        cout << -1 << '\n';
        return 0;
    }
    cout << maxS.size() << '\n' << maxC << " " << maxR << '\n';
    for(set<int>::iterator it = maxS.begin(); it!=maxS.end(); it++)
        cout << *it << " ";
    return 0;

}
