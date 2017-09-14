#include <cstdio>
#include <vector>
using namespace std;
bool vis[2001];
int q[2001];
vector<int> adj[2001];
int main() {
	int n, m, a, b, x = 0, y = 0;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int f = 0, r = 0, v = a;
	q[++r] = v;
	vis[v] = 1;
	while (f != r) {
		v = q[++f];
		for (int i = 0; i<adj[v].size(); i++) {
			if (!vis[adj[v][i]]) {
				q[++r] = adj[v][i];
				vis[adj[v][i]] = 1;
			}
		}
	}
	if (vis[b])
		printf("GO SHAHIR!\n");
	else
		printf("NO SHAHIR!\n");
}
