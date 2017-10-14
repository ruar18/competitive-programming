#include <iostream>
#include<string>
using namespace std;


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    string cur;
    cin >> n;
    while (n--) {
        cin >> cur;
        cout << cur.length() << '\n';
    }
    return 0;
}
