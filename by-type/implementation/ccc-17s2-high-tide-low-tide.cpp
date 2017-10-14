#include <cstdio>
#include <algorithm>
using namespace std;

int t[100];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	sort(t, t+n);
	if(n%2==0)
		for(int i = n/2-1; i >= 0; i--)
			printf("%d %d ", t[i], t[n-i-1]);
	else{
		for(int i = n/2; i>= 1; i--)
			printf("%d %d ", t[i], t[n-i]);
		printf("%d", t[0]);
	}

}