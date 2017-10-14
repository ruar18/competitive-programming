#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int mode[100001], n, w, box[1000], maxMode, cnt, ans, mean, modeMean, median, optim;
int main(){
    scan(n);
    for(int i = 0; i < n; i++){
        scan(w);
        mode[w]++;
        mean += w;
        box[i]=w;
    }
    mean/=n;
    for(int i = 1; i < 100001; i++){
        if(mode[i]>maxMode) {maxMode = mode[i]; modeMean = i; cnt=1; }
        else if(mode[i]==maxMode) {modeMean+=i; cnt++;}
    }
    modeMean/=cnt;
    sort(box, box+n);
    if(n%2==0) median = (box[n/2]+box[n/2-1])/2;
    else median = box[n/2];
    optim = min(min(modeMean, median), mean);
    for(int i = 0; i < n; i++) if(box[i]<=optim) ans++;
    printf("%d\n", ans);
}
