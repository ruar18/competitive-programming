#include <cstdio>
using namespace std;

int main(){
	int s1=100, s2=100, n, a, d;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &a, &d);
        if(a==d)
            continue;
        if(a < d)
            s1 -= d;
        else
            s2 -= a;
    }
    printf("%d\n%d\n", s1, s2);
    return 0;
}
