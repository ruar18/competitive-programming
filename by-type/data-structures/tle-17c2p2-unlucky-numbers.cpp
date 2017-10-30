#include <bits/stdc++.h>
using namespace std;

vector<int> unluck;
int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int k, u, n, f, maxu=0;
	cin >> k;
	while(k--){
		cin >> u;
		if(u>maxu)maxu=u;
		unluck.push_back(u);
	}
	sort(unluck.begin(), unluck.end());
	cin >> n;
	while(n--){
		cin >> f;
		if(u>maxu) cout << unluck.size() << '\n';
		else cout << f - (upper_bound(unluck.begin(), unluck.end(), f) - unluck.begin()) << '\n';
	}
	return 0;
}