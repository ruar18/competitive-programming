#include <string>
#include <vector>
#include <iostream>
using namespace std;
int l;
vector<vector<char> > c;

void go(int i, string s) {
	if (i == c.size())
		return;
	for (int j = 0; j < c[i].size(); j++) {
		if (s.length() >= l)
			return;
		cout << s + c[i][j] << '\n';
		for (int k = 1; k < c.size() - i; k++)
			go(i + k, s + c[i][j]);
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, m = 0;
	cin >> n >> l;
	char curr = ' ';
	while (n--) {
		cin >> m;
		vector<char> temp;
		while (m--)
		{
			cin >> curr;
			temp.push_back(curr);
		}
		c.push_back(temp);
	}
	go(0, "");
	return 0;
}