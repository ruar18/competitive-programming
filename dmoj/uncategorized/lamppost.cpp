#include <cstdio>
using namespace std;

int ar[1000002];
int main()
{ 
	int n, c, a = 0, b = 0;
	scanf("%d%d", &n, &c);
	for (int i = 0; i < c; i++) {
		scanf("%d%d", &a, &b);
		ar[a]++;
		ar[b]++;
	}
	int maxi = 0;
	for(int i =1; i <= n; i++){
		if (ar[i] >= ar[maxi])
			maxi = i;
	}
	printf("%d\n", maxi);
    return 0;
}