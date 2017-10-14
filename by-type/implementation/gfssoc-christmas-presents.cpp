#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

pair<long double, string> pre[20];
pair<int, string> tea[20];
int main()
{ 
	cin.sync_with_stdio(0);
	cin.tie(0);
	int p, t;
	cin >> p >> t;
	long double c = 0;
	string name = "";
	for (int i = 0; i < p; i++) {
		cin.ignore();
		getline(cin, name);
		cin >> c;
		pre[i] = make_pair(c, name);
	}
	int stuff = 0;
	for (int i = 0; i < t; i++) {
		cin.ignore();
		getline(cin, name);
		cin >> stuff;
		tea[i] = make_pair(stuff, name);
	}
	sort(pre, pre + p);
	sort(tea, tea + t);
	for (int i = 0; i < t; i++) {
		cout << tea[i].second << " will get a " << pre[i].second << '\n';
	}
    return 0;
}
