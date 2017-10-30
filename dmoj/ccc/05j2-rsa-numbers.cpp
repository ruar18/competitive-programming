#include <cstdio>
using namespace std;

int main(){
	int a, b, ans=0, temp=0;
	scanf("%d%d", &a, &b);
	for(int i = a; i<=b; i++){
		temp=0;
		for(int j = 1; j <= i; j++){
			if(i%j==0) temp++;
			if(temp>4) break;
		}
		if(temp==4) ans++;
	}
	printf("The number of RSA numbers between %d and %d is %d", a, b, ans);
	return 0;
}