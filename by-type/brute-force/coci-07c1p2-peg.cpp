#include <bits/stdc++.h>
using namespace std;

string cur;
char board[7][7];
bool legal(int i, int j){
    if(i<0||j<0||i>6||j>6) return 0;
    return 1;
}

int main(){
    for(int i = 0; i < 7; i++){
        getline(cin, cur);
        for(int j = 0; j < 7; j++)
            board[i][j]=cur[j];
    }
    int ans=0;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            if(board[i][j]=='o'){
                // right
                if(legal(i,j+1)&&board[i][j+1]=='o' && legal(i,j+2) && board[i][j+2]=='.') ans++;
                // left
                if(legal(i,j-1)&&board[i][j-1]=='o' && legal(i,j-2) && board[i][j-2]=='.') ans++;
                // down
                if(legal(i+1,j)&&board[i+1][j]=='o' && legal(i+2,j) && board[i+2][j]=='.') ans++;
                // up
                if(legal(i-1,j)&&board[i-1][j]=='o' && legal(i-2,j) && board[i-2][j]=='.') ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}