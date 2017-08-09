#include <iostream>
#include <set>
#include <string>
using namespace std;

multiset<int> blue, pink, green;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int q;
	long long num = 0;
	cin >> q;
	string op = "", col = "";
	while (q--) {
		cin >> op;
		if (op == "ADD") {
			cin >> col >> num;
			if (col == "BLUE") {
				blue.insert(num);
			}
			else if (col == "PINK") {
				pink.insert(num);
			}
			else {
				green.insert(num);
			}
		}
		else {
			if (blue.size() > 0) {
				cout << "BLUE " << *blue.begin() << '\n';
				blue.erase(blue.begin());
				continue;
			}
			else if (pink.size() > 0) {
				cout << "PINK " << *pink.begin() << '\n';
				pink.erase(pink.begin());
				continue;
			}
			else if (green.size() > 0) {
				cout << "GREEN " << *green.begin() << '\n';
				green.erase(green.begin());
				continue;
			}
			else {
				cout << "NONE\n";
			}
		}
	}
    return 0;
}