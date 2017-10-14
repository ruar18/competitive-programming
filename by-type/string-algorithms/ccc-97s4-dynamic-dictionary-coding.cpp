#include <unordered_map>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		unordered_map<string, int> dict;
		string line;
		getline(cin, line);
		int c = 1;
		while (line!=""){
			istringstream iss(line);
			string word;
			while (iss >> word) {
				if (dict.find(word) != dict.end()) {
					cout << dict.find(word)->second << " ";
				}
				else {
					cout << word << " ";
					dict.insert(make_pair(word, c++));
				}
			}
			getline(cin, line);
			if(line != "")
				cout << '\n';
		}
		cout << '\n';
	}
}