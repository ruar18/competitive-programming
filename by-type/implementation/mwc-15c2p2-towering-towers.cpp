#include <cstdio>
#include <stack>
#include <utility>
#define INF 2000000
using namespace std;
stack<pair<int, int>> hs;
int main() {
    int n;
    scanf("%d", &n);
    hs.push(make_pair(INF, 0));
    for(int i = 0, h=0; i < n; i++){
        scanf("%d", &h);
        // Pop everything lower, since this will be a new start
        while(h >= hs.top().first)
            hs.pop();
        printf("%d ", i - hs.top().second);
        hs.push(make_pair(h, i));
    }
    return 0;
}