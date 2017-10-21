#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    string word="";
    int ans=0;
    while(cin >> word) ans++;
    cout << ans << '\n';
    return 0;
}
