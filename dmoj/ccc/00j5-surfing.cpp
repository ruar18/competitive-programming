#include <bits/stdc++.h>
using namespace std;
int n, cnt, vis[10002], f;
string idstr[10002];
map<string, int> strid;
string cur, ex="<A HREF=\"";
vector<int> adj[10002];
bool bfs(int s, int t){
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto v:adj[cur]){
            if(v==t) return 1;
            if(!vis[v]){
                q.push(v);
                vis[v]=1;
            }
        }
    }
    return vis[t];
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    if(cin.peek() == '\n') cin.ignore();
    while(n--){
        getline(cin, cur);
        if(strid.count(cur)==0) {strid[cur]=cnt; idstr[cnt++] = cur;}
        int parent=strid[cur];
        getline(cin, cur);
        while(cur!="</HTML>"){
            while(cur.find(ex)!=string::npos){
                cur = cur.substr(cur.find(ex));
                string url="";
                for(unsigned int i = cur.find("=")+2; i<cur.size(); i++){
                    if(cur[i]=='"' && i<cur.size()-1 && cur[i+1]=='>') {f=1; break;}
                    url += cur[i];
                }
                if(!f) continue;
                cur = cur.substr(cur.find("\">"));
                if(strid.count(url)==0) {strid[url]=cnt; idstr[cnt++] = url;}
                adj[parent].push_back(strid[url]);
                cout << "Link from " << idstr[parent] << " to " << url << '\n';
            }
            getline(cin, cur);
        }
    }
    string url1="", url2="";
    getline(cin, url1);
    while(url1!="The End"){
        getline(cin, url2);
        if(bfs(strid[url1], strid[url2])) cout << "Can surf from " << url1 << " to " << url2 << ".\n";
        else cout << "Can't surf from " << url1 << " to " << url2 << ".\n";
        getline(cin, url1);
    }
    return 0;
}
