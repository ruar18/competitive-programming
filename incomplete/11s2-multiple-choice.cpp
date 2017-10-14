#include <iostream>
using namespace std;

char a[10000], t;
int n, ans;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        cin >> t;
        if(t==a[i]) ans++;
    }
    cout << ans << '\n';
}
