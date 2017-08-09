#include <string>
#include <iostream>

using namespace std;


int main()
{
	int shift = 0;
	// Message is the encrypted message, clear is a substring of the decrypted text
	string message, clear;
	cin >> message >> clear;
	while (message.find(clear) == string::npos) {
		for (int i = 0; i < message.size(); i++) {
			message[i]--;
			if (message[i] < 'a')
				message[i] = 'z';
		}
		shift++;
	}
	cout << shift << endl;
	cout << message << endl;
	return 0;
}
