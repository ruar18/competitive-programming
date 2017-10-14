#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n, cnt = 0;
string a, b;
vector<int> g[1000];
unordered_map<string, int> si;
unordered_map<int, string> is;
int in[1000], q[1000];
vector<int> sorted;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (si.find(b) == si.end()) {
            si.insert(make_pair(b, cnt));
            is.insert(make_pair(cnt++, b));
        }
        if (si.find(a) == si.end()) {
            si.insert(make_pair(a, cnt));
            is.insert(make_pair(cnt++, a));
        }


        g[si[b]].push_back(si[a]);
        in[si[a]]++;
    }
    priority_queue<int> q;
    for (int i = 0; i < cnt; i++) {
        if (!in[i]) {
            q.push(-i);
        }
    }

    while (!q.empty()) {
        int cur = -q.top();
        sorted.push_back(cur);
        q.pop();
        for (int v:g[cur]) {
            if (!--in[v]) q.push(-v);
        }
    }
    for (int i = 0; i < sorted.size(); i++) {
        cout << is[sorted[i]] << endl;
    }

    return 0;
}
