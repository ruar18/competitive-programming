#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

string s;
set<string> combs;
void go(string held, string varied){
	if(varied.size() == 1){
		combs.insert(varied);
		return;
	}
	if(varied.size() == 2){
		combs.insert(held + varied);
		string temp = {varied[1], varied[0]};
		combs.insert(held + temp);
		return;
	}
	for(int i = 0; i < varied.size(); i++)
		go(held + varied[i], varied.substr(0, i) + varied.substr(i+1));
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	go("", s);
	for(auto it = combs.begin(); it != combs.end(); it++)
		cout << *it << '\n';
}