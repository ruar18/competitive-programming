#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int min(int arr[5]) {
	int *m = min_element(arr, arr+5);
	for (int i = 0; i < 5; i++)
		if (arr[i] == *m)
			return i;
}

int main()
{
	string v = "aeiou", word, newW = "";
	int ds[5];
	cin >> word;
	for (int i = 0; i < word.size(); i++) {
		char c = word[i];
		newW += c;
		// If vowel
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			continue;
		// Find closest vowel
		for (int i = 0; i < 5; i++)
			ds[i] = abs(c - v[i]);
		newW += v[min(ds)];
		// Find next consonant
		char next = ' ';
		if (c == 'z')
			next = 'z';
		else if (c == 'd' || c == 'h' || c == 'n' || c == 't')
			next = c + 2;
		else
			next = c + 1;
		newW += next;
	}
	cout << newW << endl;
    return 0;
}