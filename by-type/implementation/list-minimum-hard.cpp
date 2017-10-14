#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[100000],n;
int main() {
    memset(a,0x3f,sizeof(a));
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++)printf("%d\n",a[i]);
    return 0;
}
