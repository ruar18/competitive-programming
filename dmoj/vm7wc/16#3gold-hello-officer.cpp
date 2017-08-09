#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;

// adjacency list: (node number, weight)
vector<vector<pair<int, int>>> graph(2001);
// Visited array and distances
bool visited[2001];
int dist[2001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	memset(dist, inf, sizeof(dist));
	// Num of houses, roads, date's number, queries
	int N, M, B, Q;
	cin >> N >> M >> B >> Q;
	// Construct the graph while there are still connections to be made
	for (int i = 0; i < M; i++) {
		// First node, second node, weight
		int u, v, w;
		cin >> u >> v >> w;
		// Establish connection between nodes
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}

	// Store current shortest nodes:
	// (distance, node number)
	priority_queue<pair<int, int>> q;
	// Distance to starting node is 0
	dist[B] = 0;
	q.push(make_pair(0, B));

	while (!q.empty()) {
		// Current node to inspect (remember computerphile video)
		int u = q.top().second;
		// Pop it since you don't need to inspect it anymore
		q.pop();
		visited[u] = 1;
		// Loop through all u's neighbours to see which one's the shortest
		for (int i = 0; i < graph[u].size(); i++)
		{
			// If you haven't visited that neighbour node yet, do so
			if (!visited[graph[u][i].first]) {
				// Set the distance to that node as the
				// combined distance: node b to node a and node a to start
				int w = dist[u] + graph[u][i].second;
				// If this distance is less than the current distance,
				// set it as the new current distance
				if (w < dist[graph[u][i].first]) {
					dist[graph[u][i].first] = w;
					// Send it back to inspection!
					q.push(make_pair(-w, graph[u][i].first));
				}
			}
		}
	}

	for (int i = 0; i < Q; i++) {
		int target;
		cin >> target;
		if (dist[target] == inf)
			cout << -1 << '\n';
		else
			cout << dist[target] << '\n';
	}
	return 0;
}