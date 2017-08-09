#include <iostream>
#include <string>
using namespace std;

// Calculates n mod m
int mod(int n, int m) {
	while (n < 0)
		n += m;
	return n%m;
}

char nextLetter(int letter, int posInWord, int k) {
	letter -= ('A' - 1);
	int shift = 3 * posInWord + k;
	letter -= shift;

	if (letter == 0)
		return 'Z';
	letter = mod(letter, 26);
	return 'A' + letter - 1;
}
int main()
{
	int k;
	cin >> k;
	string word;
	cin >> word;
	string cleartext = "";
	for (int i = 0; i < word.length(); i++) {
		int pos = i + 1;
		cleartext += nextLetter(word[i], pos, k);
	}
	cout << cleartext << endl;
    return 0;
}