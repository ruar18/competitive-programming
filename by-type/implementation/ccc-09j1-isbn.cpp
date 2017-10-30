#include <cstdio>
using namespace std;

int main(){
	int a, b, c, sum=91;
	scanf("%d%d%d", &a, &b, &c);
	printf("The 1-3-sum is %d", sum+a+b*3+c);
	return 0;
}