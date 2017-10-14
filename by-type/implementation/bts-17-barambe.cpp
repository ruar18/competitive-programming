#include <iostream>
#include <string>
using namespace std;
int main()
{
	string line, ans;
	getline(cin, line);
	ans += line[0];
	for (int i = 1; i < line.size(); i++) {
		if (line[i] == ' ' && i != line.size() - 1 && isupper(line[i + 1]))
		{
			ans += ". ";
			continue;
		}
		ans += line[i];
	}
	ans += ".";
	cout << ans << endl;
    return 0;
}