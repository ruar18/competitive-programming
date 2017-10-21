#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#include <cstdio>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, vector<int>> g;
unordered_map<int, int> in;
vector<int> sorted;
int x, y;

int main(){
    g[1].push_back(7);
    g[1].push_back(4);
    g[2].push_back(1);
    g[3].push_back(4);
    g[3].push_back(5);
    in[1]=1; in[2]=0; in[3]=0; in[4]=2; in[5]=1; in[6]=0; in[7]=1;
    scan(x); scan(y);
    while(x&&y){
        g[x].push_back(y);
        in[y]++;
        scan(x); scan(y);
    }
    priority_queue<int> q;
    // If no incoming edges
    for(pair<int, int> p:in){
        if(!p.second) q.push(-p.first);
    }
    while(!q.empty()){
        int cur = -q.top();
        sorted.push_back(cur);
        q.pop();
        for(int v:g[cur]) if(!--in[v]) q.push(-v);
    }
    for(pair<int, int> p:in){
        if(p.second) {
            printf("Cannot complete these tasks. Going to bed.");
            return 0;
        }
    }
    for(int v:sorted) printf("%d ", v);
    return 0;
}
