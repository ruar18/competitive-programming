#include <bits/stdc++.h>
#define MAXN 1026
using namespace std;
typedef unsigned long long ll;

int BIT[MAXN][MAXN], op, s;

void update(int x, int y, int v){
    for(; x<=s; x+=x&-x) for(int y1=y; y1<=s; y1+=y1&-y1) BIT[x][y1]+=v;
}

int rsq(int x, int y){
    int sum=0;
    for(; x; x-=x&-x) for(int y1=y; y1; y1-=y1&-y1) sum+=BIT[x][y1];
    return sum;
}

int main(){
    scanf("%d", &op);
    while(op!=3){
        if(op==0){
            scanf("%d", &s);
        }
        else if(op==1){
            int x, y, a;
            scanf("%d%d%d", &x, &y, &a);
            x+=1; y+=1;
            update(x, y, a);
        }
        else{
            int l, b, r, t;
            scanf("%d%d%d%d", &l, &b, &r, &t);
            // 1 indexing
            l+=1; b+=1; r+=1; t+=1;
            printf("%d\n", rsq(r, t) - rsq(r, b-1) - rsq(l-1, t) + rsq(l-1, b-1));
        }
        scanf("%d", &op);
        if(op==3) break;
    }
    return 0;
}
