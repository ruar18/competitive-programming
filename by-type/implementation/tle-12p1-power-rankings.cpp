#include <iostream>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
pair<int, string> students[100];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    string curr = "";
    for(int i = 0; i < n; i++){
        cin >> curr;
        students[i] = make_pair(0, curr);
    }
    int t = 0;
    for(int i = 0; i < p; i++){
        for(int j = 0; j < n; j++){
            cin >> t;
            students[j].first += t;
        }
    }
    sort(students, students+n, greater<>());
    for(int i = 0;i < n; i++)
        cout << 3 + i << ". " << students[i].second << endl;
    return 0;
}