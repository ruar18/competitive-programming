#include <cstdio>
using namespace std;
int top[100000], branch[100001];

bool check(int n) {
    int next = 1, l = 0, t = n-1, b = 0;
    while (l < n) {
        if (top[t] == next) {
            t--;
            next++;
            l++;
        }
        else if (branch[b] == next) {
            b--;
            next++;
            l++;
        }
        else
            branch[++b] = top[t--];
        if (t < 0 && branch[b] != next && l < n)
            return 0;
    }
    return 1;
}

int main()
{
    int t, n = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &top[i]);
        if (check(n))
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}