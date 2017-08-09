#include <stdio.h>

using namespace std;

int main()
{
    int x, m, n = 0, num = 0;
    scanf("%d\n%d", &x, &m);
    num = m+1;
    while(num/x<m)
    {
       if(num%x == 0)
       {
           printf("%d",num/x);
           return 0;
       }
       num+=m;
    }
    printf("No such integer exists.");
    return 0;
}