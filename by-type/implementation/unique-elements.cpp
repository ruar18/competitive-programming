#include <set>
#include <cstdio>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	set<long long> s;
	long long c = 0;
	while(n--){
		scanf("%lld", &c);
		s.insert(c);
	}
	printf("%d", s.size());
}