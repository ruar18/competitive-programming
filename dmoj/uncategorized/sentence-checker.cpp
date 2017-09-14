#include <iostream>
#include <set>
#include <string>
#include <sstream>
using namespace std;

set<string> dict;
int main()
{ 
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string t = "";
	while (n--) {
		cin >> t;
		dict.insert(t);
	}
	cin.ignore();
	bool f = 1;
	string line;
	getline(cin, line);
	istringstream iss(line);
	while(iss >> t){
		if (dict.find(t) == dict.end())
			f = 0;
	}
	cout << (f ? "Correct" : "Incorrect") << '\n';
    return 0;
}