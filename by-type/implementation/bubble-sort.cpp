#include <cstdio>
#include <algorithm>
using namespace std;

int a[20];

void print(int n){
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int n, t=0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    print(n);
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(a[j] > a[j+1]){
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                print(n);
            }
        }
    }
    return 0;
}
