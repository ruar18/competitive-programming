#include <bits/stdc++.h>
#define MAXN 2005
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<pair<int, long long>, int> piii;

struct E{
    int d, tm, dmg;
};

int k, n, m, a, b, t, h, source, dest;
long long dis[MAXN][205];
vector<E> adj[MAXN];
priority_queue<piii> q;

int main(){
    memset(dis, INF, sizeof(dis));
    scanf("%d%d%d", &k, &n, &m);
    for(int i= 0; i < m; i++){
        scanf("%d%d%d%d", &a, &b, &t, &h);
        adj[a].push_back(E{b, t, h}); adj[b].push_back(E{a, t, h});
    }
    scanf("%d%d", &source, &dest);
    dis[source][0]=0;
    q.push({{0, 0}, source});
    while(!q.empty()){
        piii curr = q.top(); q.pop();
        curr.first.first*=-1;
        if(dis[curr.second][curr.first.second]!=curr.first.first) continue;
        for(E v:adj[curr.second]){
            if(curr.first.second + v.dmg < k &&
               dis[v.d][curr.first.second + v.dmg] > curr.first.first + v.tm){
                    dis[v.d][curr.first.second+v.dmg] = curr.first.first + v.tm;
                    q.push({{-dis[v.d][curr.first.second+v.dmg], curr.first.second+v.dmg}, v.d});
               }
        }
    }
    bool f=0; long long mindist=INF;
    for(int i = 0; i < k; i++){
        if(dis[dest][i]<mindist) {mindist=dis[dest][i]; f=1;}
    }
    if(!f) printf("-1");
    else printf("%lld", mindist);
}
