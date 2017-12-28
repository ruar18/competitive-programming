#include <bits/stdc++.h>
#define MAXN 500009
using namespace std;

int n, q, arr[MAXN], l[MAXN][2], r[MAXN][2], a, b;

int main(){
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    int mn=arr[1], occ=1;
    for(int i = 2; i <= n; i++){
        l[i][0] = mn, l[i][1]=occ;
        if(arr[i]==mn) occ++;
        if(arr[i]>mn){mn = arr[i]; occ=1;}
    }
    mn = arr[n], occ=1;
    for(int i = n-1; i>=1; i--){
        r[i][0]=mn, r[i][1]=occ;
        if(arr[i]==mn) occ++;
        if(arr[i]>mn){mn=arr[i]; occ=1;}
    }
    while(q--){
        scanf("%d %d", &a, &b);
        if(l[a][0]==r[b][0]) printf("%d %d\n", l[a][0], l[a][1]+r[b][1]);
        if(l[a][0]>r[b][0]) printf("%d %d\n", l[a][0], l[a][1]);
        if(l[a][0]<r[b][0]) printf("%d %d\n", r[b][0], r[b][1]);
    }
}
