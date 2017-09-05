#include <cstdio>
#include <algorithm>
using namespace std;

int sums[4001], lengths[2001];
int main()
{
    int n, temp=0, maxe=0, l=0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        lengths[temp]++;
    }
    for(int i = 1; i <= 2000; i++){
        for(int j = i; j <= 2000; j++){
            if(i==j) sums[i+j] += lengths[i]/2;
            else sums[i+j] += min(lengths[i], lengths[j]);
        }
    }

    for(int i = 1; i <= 4000; i++){
        if(sums[i] == maxe) l++;
        else if(sums[i] > maxe) {
            maxe = sums[i];
            l=1;
        }
    }
    printf("%d %d", maxe, l);
    return 0;
}
