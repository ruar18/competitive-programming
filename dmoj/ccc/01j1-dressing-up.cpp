#include <stdio.h>

using namespace std;

int main()
{
    int H, num=1, isFlip=0;
    scanf("%d", &H);
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < num; j++)
            printf("*");
        for(int j = 0; j < 2*H - 2*num; j++)
            printf(" ");
        for(int j = 0; j < num; j++)
            printf("*");
        if(num == H)
            isFlip = 1;
        if(isFlip)
            num-=2;
        else
            num+=2;
        printf("\n");
    }
    return 0;
}