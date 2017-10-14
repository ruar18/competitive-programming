#include <iostream>
using namespace std;

struct node {
	int depth, val;
};

bool adj[50][50];
void setup() {
	adj[1][6] = 1;

	adj[2][6] = 1;

	adj[3][6] = 1;
	adj[3][4] = 1;
	adj[3][5] = 1;
	adj[3][15] = 1;

	adj[4][3] = 1;
	adj[4][5] = 1;
	adj[4][6] = 1;

	adj[5][4] = 1;
	adj[5][6] = 1;
	adj[5][3] = 1;

	adj[6][2] = 1;
	adj[6][1] = 1;
	adj[6][3] = 1;
	adj[6][4] = 1;
	adj[6][5] = 1;
	adj[6][7] = 1;

	adj[7][6] = 1;
	adj[7][8] = 1;

	adj[8][7] = 1;
	adj[8][9] = 1;

	adj[9][8] = 1;
	adj[9][10] = 1;
	adj[9][12] = 1;

	adj[10][9] = 1;
	adj[10][11] = 1;

	adj[11][10] = 1;
	adj[11][12] = 1;

	adj[12][9] = 1;
	adj[12][11] = 1;
	adj[12][13] = 1;

	adj[13][12] = 1;
	adj[13][15] = 1;
	adj[13][14] = 1;

	adj[14][13] = 1;

	adj[15][13] = 1;
	adj[15][3] = 1;

	adj[16][17] = 1;
	adj[16][18] = 1;

	adj[17][18] = 1;
	adj[17][16] = 1;

	adj[18][16] = 1;
	adj[18][17] = 1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	setup();
	char op = ' ';
	int a = 0, b = 0, cnt=0, f=0, r=0;
	while (op != 'q') {
		cin >> op;
		if (op == 'q') break;
		else if (op == 'i') {
			cin >> a >> b;
			adj[a][b] = 1;
			adj[b][a] = 1;
		}
		else if (op == 'd') {
			cin >> a >> b;
			adj[a][b] = 0;
			adj[b][a] = 0;
		}
		else if (op == 'n') {
			cin >> a;
			cnt = 0;
			for (int i = 1; i < 50; i++)
				cnt += adj[a][i];
			cout << cnt << '\n';
		}
		else if (op == 'f') {
			int vis[50] = { 0 };
			cin >> a;
			cnt = 0;
			for (int i = 1; i < 50; i++) {
				if (adj[a][i]) {
					for (int j = 1; j < 50; j++) {
						if (!vis[j] && j != a && !adj[a][j] && adj[i][j]) {
							cnt += adj[i][j];
							// fix friends of friends issue
							vis[j] = 1;
						}
					}
				}
			}
			cout << cnt << '\n';
		}
		else if (op == 's') {
			bool vis[50] = { 0 };
			node arr[50] = { 0,0 };
			int q[50] = { 0 };
			cin >> a >> b;
			vis[a] = 1;
			f = 0;
		    r = 0;
			int v = a;
			arr[a] = { 0, a };
			q[++r] = a;
			while (f != r && v != b) {
				v = q[++f];
				if (v == b) break;
				for (int i = 1; i < 50; i++) {
					if (adj[v][i] && !vis[i])
					{
						vis[i] = 1;
						q[++r] = i;
						arr[i] = { arr[v].depth + 1, i };
					}
				}
			}
			if (!vis[b]) {
				cout << "Not connected" << '\n';
				continue;
			}
			cout << arr[b].depth << '\n';
		}
	}
}