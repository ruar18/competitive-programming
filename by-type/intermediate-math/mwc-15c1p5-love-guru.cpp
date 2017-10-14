#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
typedef unsigned long long ull;
char a[1000000], b[1000000];

ull power(ull base, ull exp) {
	if (exp == 1) return base % 10;
	ull temp = power(base, exp / 2) % 10;
	if (exp % 2 == 0) return (temp % 10)*(temp % 10) % 10;
	return (temp % 10)*(temp % 10)*(base % 10) % 10;
}
int main()
{
	cin >> a >> b;
	unsigned long long suma = 0, sumb = 0;
	for (int i = 0; i < 1000000 && a[i] != '\0'; i++) {
		if (isupper(a[i]))
			suma += power((a[i] - 'A' + 1)%10, i + 1);
		else
			suma += power((a[i] - 'a' + 1)%10 , i + 1)%10;
		suma %= 10;
	}
	suma %= 10;
	for (int i = 0; i < 1000000 && b[i] != '\0'; i++) {
		if (isupper(b[i]))
			sumb += power((b[i] - 'A' + 1)%10, i + 1)%10;
		else
			sumb += power((b[i] - 'a' + 1)%10, i + 1)%10;
		sumb %= 10;
	}
	suma %= 10;
	sumb %= 10;
	if (suma == 0)
		suma = 10;
	if (sumb == 0)
		sumb = 10;
	cout << suma + sumb << endl;
    return 0;
}