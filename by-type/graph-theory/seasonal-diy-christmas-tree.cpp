#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> orig[50001], newG[50001], sorted;
int n, k, cur, in[50001], conv[50001], cnt=1;

void dfs(int s){
	for(int i = orig[s].size()-1; i >= 0; i--){
		newG[++cnt].push_back(conv[s]);
		conv[orig[s][i]] = cnt;
		in[conv[s]]++;
		dfs(orig[s][i]);
	}
}

int main(){
	scan(n);
	for(int i = 0; i < n; i++){
		scan(k);
		for(int j = 0; j < k; j++) {scan(cur); orig[i+1].push_back(cur);}
	}
	conv[1]=1;
	dfs(1);
	priority_queue<int> q;
	for(int i = 1; i <= n; i++) if(!in[i]) q.push(-i);
	while(!q.empty()){
		cur = -q.top();
		sorted.push_back(cur);
		q.pop();
		for(int v : newG[cur]) if(!--in[v]) q.push(-v);
	}
	for(int i = sorted.size()-1; i >= 0; i--) printf("%d ", sorted[i]);
	return 0;
}