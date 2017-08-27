#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first != b.first? a.first > b.first : a.second < b.second;
}
multiset<int> bags;
int n, k, m, v, c;
vector<pair<int, int>> loot;
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &m, &v);
        loot.push_back(make_pair(v, m));
    }
    for(int i = 0; i < k; i++){
        scanf("%d", &c);
        bags.insert(c);
    }
    sort(loot.begin(), loot.end(), cmp);
    unsigned long long sum = 0;
    for(int i = 0; i < n && !bags.empty(); i++){
        auto it = bags.lower_bound(loot[i].second);
        if(it != bags.end()){
            sum += loot[i].first;
            bags.erase(it);
        }
    }
    printf("%lld", sum);
}