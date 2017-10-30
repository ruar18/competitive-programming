#include <cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	if(n!=4&&n!=1){
		printf(" * * * \n");
	}
	if(n==0||n==4||n==8||n==9){
		printf("*     *\n*     *\n*     *\n");
	}
	else if(n==1||n==2||n==3||n==7){
		printf("      *\n      *\n      *\n");
	}
	else{
		printf("*      \n*      \n*      \n");
	}
	if(n!=0&&n!=1&&n!=7){
		printf(" * * * \n");
	}
	if(n==0||n==6||n==8){
		printf("*     *\n*     *\n*     *\n");
	}
	else if(n==1||n==3||n==4||n==5||n==7||n==9){
		printf("      *\n      *\n      *\n");
	}
	else{
		printf("*      \n*      \n*      \n");
	}
	if(n!=1&&n!=4&&n!=7){
		printf(" * * * ");
	}

	return 0;
}