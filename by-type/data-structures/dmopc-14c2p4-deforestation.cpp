#include <iostream>
using namespace std;

int A[1000000];
int main()
{

	// Number of trees
	int N;
	scanf("%d %d", &N, &A[0]);
	// Read in values for mass of trees
	for (int i = 1; i < N; i++) {
		scanf("%d", &A[i]);
		A[i] += A[i-1];
	}

	// Number of queries
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if(a == 0)
            printf("%d\n", A[b]);
        else
            printf("%d\n", A[b] - A[a-1]);
	}
    return 0;
}