#include <cstdio>
using namespace std;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int ans=n;
	while(n>=k){
		ans += n/k;
		n = n/k + n%k;
	}
	printf("%d\n", ans);
}