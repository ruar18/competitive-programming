#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, a, arr[51], st=0, ans=0;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a);
        if(i==k) st=a;
        arr[i]=a;
    }
    for(int i = 1; i<=n; i++){
        if(arr[i]>0 && arr[i] >= st)ans++;
    }
    printf("%d", ans);
    return 0;
}