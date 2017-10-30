#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	string ln;
	getline(cin, ln);
	char x = ln[2];
	int cnt=0, i=2;
	while(x!='r'){
		printf("(c%cr ", x);
		cnt++;
		x=ln[++i];
	}
	printf("x");
	while(cnt--) printf(")");
	return 0;
}