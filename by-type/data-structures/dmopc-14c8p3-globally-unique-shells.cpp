#include <cstdio>
#include <set>
using namespace std;

set<int> shells;
int main()
{ 
	int n, a, b, ans=0, t=0;
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < a; i++) {
		scanf("%d", &t);
		shells.insert(t);
	}
	for (int i = 0; i < b; i++) {
		scanf("%d", &t);
		if (shells.find(t) != shells.end())
			ans++;
	}
	printf("%d\n", n - ans);
    return 0;
}
