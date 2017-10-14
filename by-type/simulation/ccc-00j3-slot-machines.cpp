#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int q, ms[3], cap[3] = {35,100,10}, cur=0, t=0;
	scanf("%d\n%d\n%d\n%d", &q, &ms[0], &ms[1], &ms[2]);
	while(q--){
		ms[cur] = (ms[cur]+1)%cap[cur];
		if(ms[cur] == 0)
		{
			if(cur == 0)
				q+=30;
			else if(cur == 1)
				q+=60;
			else
				q+=9;
		}
		t++;
		cur++;
		if(cur == 3)
			cur = 0;
	}
	printf("Martha plays %d times before going broke.", t);
	return 0;
}