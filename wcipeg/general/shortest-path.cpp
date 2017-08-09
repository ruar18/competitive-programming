#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, arr[101][101], dis[101];
bool vis[101];

void BFS(int start) {
	queue<int> Q;
	Q.push(start); dis[start] = 0; vis[start] = 1;
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for (int i = 0; i <= N; i++)
		{
			if (arr[cur][i] == 1 && !vis[i]) {
				Q.push((i));
				vis[i] = 1;
				dis[i] = dis[cur] + 1;
			}
		}
	}
}


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
	BFS(1);
	cout << dis[N];
    return 0;
}