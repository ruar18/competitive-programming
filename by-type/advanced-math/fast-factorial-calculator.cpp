#include <cstdio>
#define T 4294967296
typedef unsigned long long ull;

ull ans, n, t;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%llu", &n);
        ans=1;
        if(n>=36) printf("0\n");
        else {for(int i = 2; i <= n; i++) ans = (ans*i)%T;
        printf("%llu\n", ans%T);}
    }
    return 0;
}
