#include <bits/stdc++.h>
using namespace std;

int prices[101], n, p, maxp, minp=1000;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &p);
        if(p>maxp) maxp=p;
        if(p<minp) minp=p;
        prices[p]++;
    }
    int lowest=minp, highest=100;
    for(int i = maxp; i >=0; i--){
        if(prices[i]>prices[highest]) highest=i;
    }
    for(int i = minp; i < maxp; i++){
        if(prices[i]!=0 && prices[i]<prices[lowest]) lowest=i;
    }
    printf("%d", abs(highest-lowest));
    return 0;
}