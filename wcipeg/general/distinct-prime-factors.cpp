#include <stdlib.h>
#include <stdio.h>
using namespace std;
int flags[1000001];
int main()
{

    int a, b;
    scanf("%d %d", &a, &b);
    for(int i = 2; i <= b; i++)
    {
        if(!flags[i])
        {
            flags[i]=1;
            for(int j = i*2; j <= b; j+=i)
                flags[j]++;
        }
    }
    for(int i = a; i <= b; i++){
        printf("%d\n", flags[i]);
    }
    return 0;
}