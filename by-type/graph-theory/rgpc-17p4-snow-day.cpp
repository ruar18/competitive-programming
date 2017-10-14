#include <iostream>
#include <list>
#include <utility>
#include <cstring>
#define NINF -0x3f3f3f3f
using namespace std;

// Use a list to insert things to the head fast
list<pair<int, int > > graph[1001];
list<int> sorted;
int marks[1001], dist[1001], points[1001];
bool cycle = 0;

// Topologically sort the nodes
void topoSort(int s){
    // If the node has been visited already, it's a cycle
    if(marks[s] == -1)
    {
        // Note that there's a cycle
        cycle = true;
        return;
    }
    // If it hasn't been visited yet, go
    if(marks[s] == 0){
        // Mark it temporarily: in process of exploration
        marks[s] = -1;
        // Loop through all childs (adjacency list in the graph)
        for(list<pair<int, int> >::iterator it = graph[s].begin(); it != graph[s].end(); ++it){
            // Explore the node
            topoSort(it->first);
            // If a cycle was found in the process, return
            if(cycle)
                return;
        }
        marks[s] = 1;
        sorted.push_front(s);
    }
}

// find the longest path, n is the number of nodes
void findPath(int n){
    for(int i = 1; i <= n; i++){
        // Topologically sort each node
        if(marks[i] == 0)
            topoSort(i);
        // If you found a cycle
        if(cycle){
            cout << -1 << '\n';
            return;
        }
    }
    // If there's no way to reach the end, it's bad
    if(!marks[n]){
        cout << -1 << '\n';
        return;
    }
    // Set all the distances to their initial state
    memset(dist, NINF, 1001);
    // The first node is 0 units away from itself
    dist[1] = 0;
    // One point is the first point
    points[1] = 1;
    int cur;
    while(!sorted.empty()){
        // Get the nodes in topological order! That's what the sorting was used for.
        cur = sorted.front();
        sorted.pop_front();
        // If the node is close enough to be traveresed (1 connection away)
        if(dist[cur] != NINF){
            // Go through the children of the node
            for(list<pair<int, int> >::iterator it = graph[cur].begin(); it != graph[cur].end(); ++it){
                // Check if the distance is greater like this
                if(dist[cur] + it->second > dist[it->first]){
                    // Record the new longest distance
                    dist[it->first] = dist[cur] + it->second;
                    points[it->first] = points[cur] + 1;
                }
                if(dist[cur] + it->second == dist[it->first] && points[cur] + 1 > points[it->first]){
                    points[it->first] = points[cur] + 1;
                }
            }
        }

    }
    cout << dist[n] << " " << points[n] << '\n';
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, d;
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> d;
        // Add to adjacency list
        graph[a].push_back(make_pair(b,d));
    }
    findPath(n);
    return 0;
}