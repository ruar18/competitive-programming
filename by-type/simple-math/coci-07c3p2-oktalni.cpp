#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	while (s.size() % 3 != 0) {
		s = "0" + s;
	}
	string res="";
	for (int i = 0; i < s.size(); i+=3) {
		string temp = { s[i], s[i + 1], s[i + 2] };
		if (temp == "000")
			res += "0";
		else if (temp == "001")
			res += "1";
		else if (temp == "010")
			res += "2";
		else if (temp == "011")
			res += "3";
		else if (temp == "100")
			res += "4";
		else if (temp == "101")
			res += "5";
		else if (temp == "110")
			res += "6";
		else if (temp == "111")
			res += "7";
	}
	cout << res << endl;
    return 0;
}
