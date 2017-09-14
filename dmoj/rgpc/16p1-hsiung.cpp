#include <iostream>
#include <algorithm>
using namespace std;

int w[2001];
int main()
{
	int a, b, c;
	cin >> a >> b >> c; 
	for (int i = 0; i <= c; i++) {
		if (w[i] != 0 || i==0) {
			w[i + a] = min(w[i] + a, i+a);
			w[i + b] = min(w[i] + b, i+b);
		}
	}
	int max = 0;
	for (int i = 1; i <= c; i++)
		if (w[i] > max)max = w[i];
	cout << max << endl;
    return 0;
}