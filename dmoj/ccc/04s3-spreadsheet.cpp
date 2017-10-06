#include <iostream>
#include <map>

using namespace std;

string sheet[11][10];
int dp[11][10];
map<pair<int, int>, int> vis;

bool isNum(string s) {
    for (char i : s) if (!isdigit(i)) return false;
    return true;
}

void dfs(int r, int c) {
    string cur = sheet[r][c];
    auto it = vis.find(make_pair(r, c));
    if (it->second == 1) {
        dp[r][c] = -1;
        return;
    } else if (it->second == 0) {
        it->second = 1;
        if (dp[r][c] != 0) return;
        if (isNum(sheet[r][c])) {
            dp[r][c] = atoi(sheet[r][c].c_str());
            it->second = 2;
            return;
        }
        while (cur.length() >= 2) {
            string tcell = cur.substr(0, 2);
            int trow = tcell[0] - 'A' + 1, tcol = tcell[1] - '0';
            dfs(trow, tcol);
            if (dp[trow][tcol] == -1) {
                dp[r][c] = -1;
                return;
            }
            dp[r][c] += dp[trow][tcol];
            if (cur.length() >= 4) {
                cur = cur.substr(3);
            } else break;
        }
        it->second = 2;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> sheet[i][j];
            vis.insert(make_pair(make_pair(i, j), 0));
        }
    }
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 9; j++)
            dfs(i, j);
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 9; j++) cout << (dp[i][j] == -1 ? "*" : to_string(dp[i][j])) << " ";
        cout << '\n';
    }
    return 0;
}