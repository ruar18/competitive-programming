/*
ID: rudyal11
PROG: crypt1
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;
vector<int> nums_3, nums_2;
set<int> digits;

// Checks if all digits of a number are in set digits, O(num_digits)
bool checkDigits(int num) {
	int d = 0;
	while (num > 0) {
		d = num % 10;
		if (digits.find(d) == digits.end())
			return 0;
		num /= 10;
	}
	return 1;
}

int main()
{
	ofstream fout("crypt1.out");
	ifstream fin("crypt1.in");
	int n;
	fin >> n;

	for (int i = 0; i < n; i++) {
		int cur;
		fin >> cur;
		digits.insert(cur);
	}

	// Generate all 3 & 2 digit combinations, O(n^3)
	for (auto i = digits.begin(); i != digits.end(); i++) {
		for (auto j = digits.begin(); j != digits.end(); j++) {
			nums_2.push_back(*i * 10 + *j);
			for (auto k = digits.begin(); k != digits.end(); k++) {
				nums_3.push_back(*i * 100 + *j * 10 + *k);
			}
		}
	}

	int ans = 0;
	for (int top : nums_3) {
		for (int bot : nums_2) {
			if (top * (bot % 10) <= 999 &&
				top * (bot / 10) <= 999 &&
				checkDigits(top * (bot % 10)) &&
				checkDigits(top * (bot / 10))) {
				if (top * bot <= 9999 && checkDigits(top * bot)) {
					ans++;
				}
			}
		}
	}

	fout << ans << endl;
	return 0;
}

