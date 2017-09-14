#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> a[100000], b[100000];
int main()
{
    int n, ai=0, bi=0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &ai, &bi);
        a[i] = make_pair(ai, i+1);
        b[i] = make_pair(bi, i+1);
    }
    sort(a, a+n);
    sort(b, b+n);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i].second);
    printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d ", b[i].second);
    return 0;
}
