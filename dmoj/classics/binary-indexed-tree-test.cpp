#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef unsigned long long ll;

int a[MAXN], n, m, le[MAXN], op1, op2, f[MAXN];
ll sum[MAXN];
char op;

void update(int v, int x){
    for(; x<=n; x+=x&(-x)) {sum[x]+=v;}
}

void update2(int v, int x){
    for(; x<=100000; x+=x&(-x)) {le[x]+=v;}
}

ll rsq(int r){
    ll s=0;
    for(; r>0; r-=r&(-r)) s+=sum[r];
    return s;
}

ll crf(int r){
    ll s=0;
    for(; r>0; r-=r&(-r)) s+=le[r];
    return s;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {scanf("%d", &a[i]); f[a[i]]++; update(a[i], i);}
    for(int i = 1; i <= 100000; i++) if(f[i]!=0) update2(f[i], i);

    while(m--){
        scanf(" %c", &op);
        if(op=='C'){
            scanf("%d%d", &op1, &op2);
            update(op2-a[op1], op1);
            update2(-1, a[op1]); update2(1, op2);
            a[op1]=op2;
        }
        else if(op=='S'){
            scanf("%d%d", &op1, &op2);
            printf("%llu\n", rsq(op2)-rsq(op1-1));
        }
        else{
            scanf("%d", &op1);
            printf("%llu\n", crf(op1));
        }
    }
    return 0;
}
