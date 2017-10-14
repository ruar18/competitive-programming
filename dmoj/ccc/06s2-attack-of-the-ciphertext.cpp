#include <iostream>
#include <string>
using namespace std;

char m[91];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    string a, b, c;
    getline(cin, a); getline(cin, b); getline(cin, c);
    for(int i = 0; i < b.size(); i++) m[b[i]] = a[i];
    for(int i = 0; i < c.size(); i++) cout << (m[c[i]]==0? '.':m[c[i]]);
    return 0;
}
