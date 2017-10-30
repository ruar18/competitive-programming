#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, ans="";
    cin >> s;
    for(char c:s){
        char cur=tolower(c);
        if(cur=='a'||cur=='o'||cur=='y'||cur=='e'||cur=='u'||cur=='i') continue;
        ans += "."; ans+=cur;
    }
    cout << ans;
    return 0;
}