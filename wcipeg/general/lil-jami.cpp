#include <iostream>

using namespace std;

int pfs[1000000];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    while(k--){
        int ki;
        cin >> ki;
        pfs[ki]++;
    }

    for(int i = 1; i < n; i++)
    {
        pfs[i] += pfs[i-1];
    }
    int q, a = 0, b=0;
    cin >> q;
    while(q--){
        cin >> a >> b;
        if(a == 0)
            cout << pfs[b] << endl;
        else
            cout << pfs[b] - pfs[a-1] << endl;
    }
    return 0;
}