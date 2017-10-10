#include <cstdio>
int main(){
    int n, a[6]={1,1,1,1,1,1};
    scanf("%d",&n);
    for(int i=1,j=0;i<n;i++){
        scanf("%d",&j);
        a[j-1]*=(a[i-1]+1);
    }
    printf("%d",a[n-1]);
    return 0;
}
