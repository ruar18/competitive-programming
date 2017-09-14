#include <cstdio>
#include <set>
using namespace std;

set<int> gates;
int main()
{ 
	int g, p, t=0, ans=0;
	scanf("%d%d", &g, &p);
	for (int i = 1; i <= g+2; i++)
		gates.insert(i);
	auto it = gates.begin();
	for (int i = 0; i < p; i++) {
		scanf("%d", &t);
		it = --gates.upper_bound(t);
		if (it != gates.end())
		{
			gates.erase(it);
			ans++;
		}
		else break;
	}
	printf("%d\n", ans);
    return 0;
}
