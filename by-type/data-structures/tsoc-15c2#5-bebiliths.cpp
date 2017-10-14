#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;

ll s;
struct bebe {
	int num;
	ll b, d, c;
} a[50001];

bool comp(bebe fir, bebe sec) {
	return fir.b==sec.b?fir.b>=s?fir.c!=sec.c?fir.c>sec.c:fir.num<sec.num:fir.d!=sec.d?fir.d>sec.d:fir.num<sec.num:fir.b>sec.b;
}

int main()
{ 
	int n,te=0;
	ll b=0, d=0, c=0;
	scanf("%lld%d", &s, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &b, &d, &c);
		a[i] = { i, b, d, c };
	}
	sort(a + 1, a + n + 1, comp);
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &te);
		printf("%d\n", a[te].num);
	}
    return 0;
}