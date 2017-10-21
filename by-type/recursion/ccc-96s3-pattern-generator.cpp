#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> ans;
void go(string cur, int tot, int left){
    if(cur.length()==tot) {ans.push_back(cur); return;}
    if(tot-cur.length()>left) go(cur+"0", tot, left);
    if(left>=1) go(cur+"1", tot, left-1);
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int l, n, k;
    cin >> l;
    while(l--){
        ans.clear();
        cin >> n >> k;
        go("", n, k);
        sort(ans.rbegin(), ans.rend());
        cout << "The bit patterns are\n";
        for(string s:ans) cout << s << '\n';
    }
    return 0;
}
