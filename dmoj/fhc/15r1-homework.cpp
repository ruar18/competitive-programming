#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;
int flags[10000001]; vector<int> f[10];

int main()
{
    for(int i = 2; i < 10000001; i++)
    {
        if(!flags[i])
        {
            for(int j = i; j < 10000001; j+=i)
                flags[j]++;
        }
    }
    for(int i = 2; i < 10000001; i++)
        f[flags[i]].push_back(i);
    int t, a=0, b=0, k=0;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d %d %d", &a, &b, &k);
        if(k >= 9)
        {
            printf("Case #%d: 0\n", i);
            continue;
        }
        // Bin search
        printf("Case #%d: %d\n", i, upper_bound(f[k].begin(), f[k].end(), b) - lower_bound(f[k].begin(), f[k].end(), a));
    }
    return 0;
}