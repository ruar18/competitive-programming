#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char plan[25][25];
int r, c, directions[8] = {-1, 0, 1, 0, 0, -1, 0, 1};

int dfs(int x, int y){
    if(x >= r || x < 0 || y >= c || y < 0 || plan[x][y] == 'I')
        return 0;
    plan[x][y] = 'X';
    int sum = 1;
    for(int i = 0; i < 7; i+=2)
        if(plan[x + directions[i]][y + directions[i+1]] != 'X')
            sum += dfs(x + directions[i], y + directions[i+1]);
    return sum;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a, cnt = 0;
    cin >> a >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> plan[i][j];

    vector<int> rooms;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(plan[i][j] == '.')
                rooms.push_back(dfs(i, j));

    sort(rooms.rbegin(), rooms.rend());
    for(int i = 0; i < rooms.size(); i++){
        if(a - rooms[i] >= 0)
        {
            a-=rooms[i];
            cnt++;
        }
        else break;
    }
    cout << cnt << " " << (cnt == 1? "room, " : "rooms, ") << a << " square metre(s) left over" << endl;
    return 0;
}

