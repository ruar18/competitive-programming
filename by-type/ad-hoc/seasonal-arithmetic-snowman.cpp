#include <cstdio>
#include <algorithm>
using namespace std;
int b[3000];

bool bin(int t, int n, int x, int y) {
	int bot = 0, top = n-1, key = 0;
	while (top >= bot) {
		key = (bot + top) / 2;
		if (b[key] == t && key != x && key != y) {
			return true;
		}
		else if (b[key] > t) top = key - 1;
		else bot = key + 1;
	}
	return false;
}

int main() {
	int n, maxs = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	sort(b, b + n);
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			if (b[j] * 3 > maxs && bin(2 * b[j] - b[i], n, i, j))
				maxs = b[j] * 3;
		}
	}

	printf("%d\n", maxs);
}