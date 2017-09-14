#include <cstdio>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){ return b==0? a : gcd(b, a%b); }

int main()
{
    ll a, b, x;
    scanf("%lld %lld %lld", &a, &b, &x);
    printf("%lld\n", (x-1)/((a*b)/gcd(a,b))+1);
    return 0;
}