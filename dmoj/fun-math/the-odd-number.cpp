#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    unordered_set<int> nums;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int number;
        cin >> number;
        if(nums.find(number) == nums.end())
            nums.insert(number);
        else nums.erase(number);
    }
    cout << *nums.begin();
    return 0;
}