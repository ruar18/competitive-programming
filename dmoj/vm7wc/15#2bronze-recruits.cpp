#include <iostream>

using namespace std;
int sol[20];


int main()
{
    int n;
    cin >> n;
    for(int i =0; i < n; i++){
        cin >> sol[i];
    }
    int ans = 0;
    if(sol[0] <= 41 && sol[1] <= 41)
        ans++;
    for(int i = 1; i < n-1; i++){
        if(sol[i] <= 41 && sol[i-1] <= 41 && sol[i+1] <= 41)
            ans++;
    }
    if(sol[n-1] <= 41 && sol[n-2] <= 41)
        ans++;

    cout << ans << endl;
    return 0;
}
