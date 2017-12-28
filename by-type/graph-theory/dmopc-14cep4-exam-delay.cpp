#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
pii adj[1002][1002];
int v, e, m, n, d, s, par[1002], numpar[1002];
double dis[1002];
priority_queue<pair<double, int>> q;

int main(){
    fill(begin(dis), end(dis), 123456789.0);
    scanf("%d%d", &v, &e);
    while(e--){
        scanf("%d%d%d%d", &m, &n, &d, &s);
        if(adj[m][n].first!=0){
            if(60.0*adj[m][n].first/adj[m][n].second < 60.0*d/s) continue;
        }
        adj[m][n] = adj[n][m] = {d, s};
    }
    dis[1]=0; par[1]=-1; q.push({0, 1}); numpar[1]=0;
    while(!q.empty()){
        double t= -q.top().first; int cur = q.top().second;
        q.pop();
        if(t!=dis[cur]) continue;
        for(int i = 1; i <= v; i++){
            double newDist = dis[cur]+60.0*adj[cur][i].first/adj[cur][i].second;
            if(adj[cur][i].first!=0){
                if(dis[i]>newDist){
                    dis[i]=newDist;
                    q.push({-newDist, i});
                    par[i]=cur;
                    numpar[i]=numpar[cur]+1;
                }
                if(dis[i]==newDist){
                    if(numpar[cur]+1<numpar[i]){
                        dis[i]=newDist;
                        q.push({-newDist, i});
                        par[i]=cur;
                        numpar[i]=numpar[cur]+1;
                    }
                }
            }
        }
    }
    double origTime=dis[v], newTime=0;
    int cur=par[v], child=v;
    while(cur!=-1){
        newTime+=60.0*(adj[cur][child].first/(0.75*adj[cur][child].second));
        child=cur; cur=par[cur];
    }
    printf("%d\n%d", numpar[v], (int)round(newTime-origTime));
    return 0;
}
