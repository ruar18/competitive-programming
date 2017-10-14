#include <cstdio>
using namespace std;

int reads[2001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &reads[i]);
	}
	int maxi = 0, mini = 0;
	for (int i = 0; i < n; i++) {
		if (reads[i] >= reads[maxi]) {
			maxi = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (reads[i] <= reads[mini]) {
			mini = i;
		}
	}
	int prev = reads[mini];
	if (mini > maxi) {
		printf("unknown\n");
		return 0;
	}

	for (int i = mini; i <= maxi; i++) {
		if (reads[i] - prev < 0) {
			printf("unknown\n");
			return 0;
		}
		prev = reads[i];
	}
	printf("%d\n", reads[maxi] - reads[mini]);
}
