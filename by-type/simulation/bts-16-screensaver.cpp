#include <iostream>
using namespace std;
char grid[100][100];


int main() {
    int d1 = 0, d2 = 1, n, m, t, r, c;;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> t;
    for(int i = 0; i < m; i++){
        cin >> grid[i];
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 'O')
            {
                r = i;
                c = j;
            }
        }
    }
    int curr = 0;

    while(1){
        r+=d1, c+=d2;
        curr++;
        if(r< 0 || c < 0 || r >= m || c >= n){
            if(curr > t){
                cout << "The observer stays within the grid.";
                return 0;
            }
            cout << "The observer leaves the grid after " << curr << " tick(s).";
            return 0;
        }

        if(grid[r][c] == '\\')
        {
            int temp = d2;
            d2 = d1;
            d1 = temp;
            grid[r][c] = '/';
        }
        else if(grid[r][c] == '/'){
            int temp = d2;
            d2 = -d1;
            d1 = -temp;
            grid[r][c] = '\\';
        }
        else if(grid[r][c] == '-'){
            if(d1 != 0){
                d1 *= -1;
                grid[r][c] = '|';
            }
        }
        else if(grid[r][c] == '|'){
            if(d2 != 0){
                d2 *= -1;
                grid[r][c] = '-';
            }
        }
    }
}