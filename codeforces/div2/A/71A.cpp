#include <bits/stdc++.h>
using namespace std;

int main(){ 
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >>n;
    string cur="";
    while(n--){
        cin>>cur;
        if(cur.length()>10){
            cout << cur[0] << cur.length()-2 << cur[cur.length()-1] << '\n';
        }
        else cout << cur << '\n';
    }
    return 0;
}