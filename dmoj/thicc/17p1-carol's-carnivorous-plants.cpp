#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int f[101];
unsigned long long power(unsigned long long x,long long n)
{
    unsigned long long ans = 1;
    while (n){
        if (n % 2 != 0) ans *= x;
        ans %=1000000007;
        x *= (x%1000000007);
        x%=1000000007;
        n /= 2;
    }
    return ans;
}

int main()
{
    long long T = 1000000007;
    // n: #flowers, m: #friends
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &f[i]);
    }

    sort(f, f+n, std::greater<long long>());

    unsigned long long cost = 0;
    // greedy
    int i =0, exponent = 0, cnt = 0;
    while(n--){
        unsigned long long p = power(f[i], exponent)%T ;
        cost += p%T;
        cost%=T;
        cnt++;
        i++;
        if(cnt >= m){
            cnt = 0;
            exponent++;
        }
    }
   printf("%lld", cost);
    return 0;
}