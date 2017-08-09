#include <iostream>

using namespace std;
long long pfs[1000000];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k >> pfs[0];
    // Construct pfs
    for(int i = 1; i < n; i++){
        cin >> pfs[i];
        pfs[i] += pfs[i-1];
    }
    long long maxi = 0, curr = 0;
    for(int i = k - 1; i < n; i++){
        curr = i == k-1? pfs[i] : pfs[i] - pfs[i-k];
        if (curr > maxi)
            maxi = curr;
    }
    cout << maxi << endl;
    return 0;
}
