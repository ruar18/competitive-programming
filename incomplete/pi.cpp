#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#include <cstdio>
#include <map>
using namespace std;

int n, k;
map<pair<int, int>, long long> lookup;

int go(int pos, int left, int prev){
    if(pos==k && left >= prev) return 1;
    long long ans=0;
    for(int i = pos<k? left/(k-pos+1):left; i >=1; i--){
        if(i < prev) break;
        pair<int, int> temp = make_pair(pos+1, left-i);
        if(lookup.count(temp) != 0)
            ans += lookup[temp];
        else{
            lookup[temp] = go(pos+1, left-i, i);
            ans += lookup[temp];
        }
        // ans += go(pos+1, left-i, i);
    }
    return ans;
}
int main(){
    scan(n); scan(k);
    if(n == k || k == 1) printf("1");
    else if(n < k) printf("0");
    else printf("%d", go(1, n, 0));
    return 0;
}
