#include <cstdio>
using namespace std;

bool flags[7001];

int jval(int n){
    if(n <= 1)
        return 0;
    else if(!flags[n])
        return 1;
    else if(n % 2 == 0)
        return 2;
    else if(!flags[n-2])
        return 2;
    else
        return 3;
}

int main()
{
    int n, k;
    if(k > 3){
        printf("%d", 0);
        return 0;
    }
	scanf("%d %d", &n, &k);
	for (int i = 2; i <= n; i++) {
		if (!flags[i]) {
			for (int j = i * i; j <= n; j += i)
				flags[j] = 1;
		}
	}
	int ans = 0;
	for(int i = 2; i <= n; i++){
	    ans += jval(i) == k;
	}
	printf("%d\n", ans);
    return 0;
}
