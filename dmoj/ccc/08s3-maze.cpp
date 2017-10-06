#include <iostream>
#include <cstring>

using namespace std;

int t, r, c, f, b, dist[20][20], rc, cc;
char g[21][21];
pair<int, int> q[401], cur;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> g[i][j];
        f = b = -1;
        memset(dist, -1, sizeof(dist));
        dist[0][0] = 1;
        q[++b] = cur = make_pair(0, 0);
        while (f != b) {
            cur = q[++f];
            rc = cur.first, cc = cur.second;
            if (g[rc][cc] == '*')continue;
            if (g[rc][cc] != '-' && rc > 0 && g[rc-1][cc]!='*'&&dist[rc - 1][cc] == -1) {
                dist[rc - 1][cc] = dist[rc][cc] + 1;
                q[++b] = make_pair(rc - 1, cc);
            }
            if (g[rc][cc] != '|' && cc > 0 && g[rc][cc-1]!='*'&&dist[rc][cc - 1] == -1) {
                dist[rc][cc - 1] = dist[rc][cc] + 1;
                q[++b] = make_pair(rc, cc - 1);
            }
            if (g[rc][cc] != '-' && rc < r - 1 && g[rc+1][cc]!='*'&&dist[rc + 1][cc] == -1) {
                dist[rc + 1][cc] = dist[rc][cc] + 1;
                q[++b] = make_pair(rc + 1, cc);
            }
            if (g[rc][cc] != '|' && cc < c - 1 && g[rc][cc+1]!='*'&&dist[rc][cc + 1] == -1) {
                dist[rc][cc + 1] = dist[rc][cc] + 1;
                q[++b] = make_pair(rc, cc + 1);
            }
        }
        if (dist[r - 1][c - 1] == -1) cout << -1 << '\n';
        else cout << dist[r - 1][c - 1] << '\n';
    }
}