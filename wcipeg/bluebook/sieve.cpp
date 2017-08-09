#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

bool flags[501];

void init(int n){
    for(int i = 2; i <= n; i++){
        if(flags[i]){
            for(int j = i*i; j <= n; j+=i)
                flags[j] = 0;
        }
    }
}
int main()
{
    memset(flags, 1, sizeof(flags));
    int n;
    scanf("%d", &n);
    init(n);
    flags[1] = 0;
    for(int i = 1; i <= n; i++)
        printf("%d\n", flags[i]);
    return 0;
}