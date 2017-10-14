#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

string a[30], b[30];
map<string, string> pairs;
int n;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    if(n%2!=0) {cout << "bad" << '\n'; return 0;};
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) pairs.insert(make_pair(a[i], b[i]));
    for(int i = 0; i < n; i++) {
        if(pairs[b[i]]!=a[i] || a[i]==b[i]) {cout << "bad" << '\n'; return 0;}
    }
    cout << "good" << '\n';
    return 0;
}
