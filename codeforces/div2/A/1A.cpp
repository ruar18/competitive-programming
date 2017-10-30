#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a;
    scanf("%d%d%d", &n,&m,&a);
    printf("%lld", (long long)(ceil(1.0*n/a)*ceil(1.0*m/a)));
    return 0;
}