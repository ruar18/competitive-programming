#include <cstdio>
using namespace std;


int main() {
    int n, cur=0, ans=0;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &cur);
        ans^=cur;
    }
    printf("%d\n", ans);
    return 0;
}
