#include <cstdio>
using namespace std;

bool tree[4][4];
int main()
{ 
	int ans = 0, t=0, f=0, temp=0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &t);
			tree[i][j] = t;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i!=j && tree[i][j] && tree[i][j] == tree[j][i]) ans++;
		}
	}
	for (int i = 0; i < 4; i++) {
		temp = 0;
		for (int j = 0; j < 4; j++)
			temp += tree[i][j];
		if (temp == 0)f = 1;
	}
	if (ans == 6 && !f)
		printf("Yes\n");
	else
		printf("No\n");
    return 0;
}