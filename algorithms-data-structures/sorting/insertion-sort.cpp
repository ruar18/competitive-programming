// Implementation of the insertion-sort sorting algorithm
// O(N^2)
#include <cstdio>
using namespace std;
#define MAXN 6

int array[MAXN];

void insertionSort(){
	// Loop through elements to place them in correct positions
	for(int i = 1; i < MAXN; i++){
		int key = array[i];
		int j= i - 1;
		// Find correct position
		for(; j >= 0 && array[j] > key; j--){
			// Shift current element one to the right
			array[j+1] = array[j];
		}
		// Place the key after the first element that is less than it
		// If key should go at index 0, then j is -1 after the loop, so it works
		array[j+1] = key;
	}
}

int main(){
	for(int i = 0; i < MAXN; i++)
		scanf("%d", &array[i]);

	insertionSort();

	for(int i = 0; i < MAXN; i++)
		printf("%d ", array[i]);

	return 0;
}
