#include <bits/stdc++.h>
using namespace std;
int w, h, n, a[251][251], pfs[251][251], cur, m, width, height;
int main(){
    scanf("%d%d%d", &w, &h, &n);
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i<=h; i++) {
        for(int j = 1; j<=w; j++) {
            pfs[i][j]=pfs[i-1][j]+pfs[i][j-1]-pfs[i-1][j-1]+a[i][j];
        }
    }
    for(int b=1; b<=n; b++){
        width=b-1, height=(n/b)-1;
        for(int i = 1; i <= h-height; i++){
            for(int j = 1; j<= w-width; j++){
                m = max(m, pfs[i+height][j+width] - pfs[i-1][j+width] - pfs[i+height][j-1] + pfs[i-1][j-1]);
            }
        }
    }
    printf("%d", m);
	return 0;
}
