#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int nums[100001];
vector<int> pre[200];
int main()
{
    pre[1].push_back(1);
    for(int i = 2; i <= 100000; i++){
        nums[i]++;
        for(int j = i; j <= 100000; j += i)
            nums[j]++;
        pre[nums[i]].push_back(i);
    }
    int k=0, a=0, b=0, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &k, &a, &b);
        printf("%d\n", k >= 200? 0 : upper_bound(pre[k].begin(), pre[k].end(), b) - lower_bound(pre[k].begin(), pre[k].end(), a));
    }
    return 0;
}