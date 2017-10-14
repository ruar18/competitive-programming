#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

pair<int, int> students[100000];
multiset<long long> microwaves;

bool c(const pair<int, int> &a, const pair<int, int> &b){
	return a.first < b.first;
}

int main()
{
	int N, M, T, ti = 0, fi = 0;
	long long curr = 0;
	scanf("%d %d %d", &N, &M, &T);
	for (int i = 0; i < N; i++)
		microwaves.insert(0);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &ti, &fi);
		students[i] = make_pair(ti, fi);
	}
	sort(students, students + M, c);
	for (int i = 0; i < M; i++) {
		ti = students[i].first, fi = students[i].second;
		auto good = microwaves.upper_bound(ti);
		long long t = *microwaves.begin();
		// Well you're gonna have to wait (if first element that is >= ti is the min element)
		if (good == microwaves.begin()) {
			microwaves.erase(microwaves.begin());
			microwaves.insert(t + fi);
			continue;
		}
		if (ti - t >= T) {
			printf("%lld\n", t);
			return 0;
		}
		// You might not have to wait!
		curr = *--good;
		microwaves.erase(good);
		microwaves.insert(ti <= curr ? curr + fi : ti + fi);
	}
	printf("%lld\n", *microwaves.begin());
	return 0;
}