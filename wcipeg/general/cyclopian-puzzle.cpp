#include <cstdio>
using namespace std;

void hanoi(int n, char start, char mid, char dest) {
	// base case
	if (n == 1) {
		printf("%c%c\n", start, dest);
		return;
	}
	// move top n-1 discs to mid peg
	hanoi(n - 1, start, dest, mid);
	// move bottom disc to destination peg
	printf("%c%c\n", start, dest);
	// move the n-1 discs that are on mid peg to destination
	hanoi(n - 1, mid, start, dest);
}
int main()
{
	int n;
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
    return 0;
}