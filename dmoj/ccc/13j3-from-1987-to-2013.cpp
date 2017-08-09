#include <stdio.h>
#include <set>
using namespace std;

bool isDis(int y)
{
	int numDig = 0;
	set<int> dig;
	while(y > 9)
	{
		dig.insert(y%10);
		y/=10;
		numDig++;
	}
	dig.insert(y);
	return dig.size() == numDig+1;
}

int main(){
	int Y;
	scanf("%d", &Y);
	while(true)
	{
		Y++;
		if(isDis(Y))
			break;
	}
	printf("%d", Y);
	return 0;
}