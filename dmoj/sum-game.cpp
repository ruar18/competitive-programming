#include <cstdio>
using namespace std;

int ga[100000], gb[100000], n;
int main()
{

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &ga[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &gb[i]);
    int tota = 0, totb=0, maxi = 0;
    for(int i = 1; i <= n; i++){
        tota+=ga[i-1];
        totb+=gb[i-1];
        if(tota==totb)
            maxi = i;
    }
    printf("%d", maxi);
    return 0;
}
