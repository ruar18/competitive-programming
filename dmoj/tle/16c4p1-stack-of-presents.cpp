#include <cstdio>
#include <algorithm>
using namespace std;

int w[100000];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &w[i]);
    }
    sort(w, w+n);
    int sum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(sum <= w[i]){
            sum += w[i];
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}