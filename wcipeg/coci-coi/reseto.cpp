#include <iostream>

using namespace std;

bool flags[1001];
int main()
{
    int N, K, cnt = 0, ans = 0;
    cin >> N >> K;
    for(int i = 2; i <= N; i++){
        if(!flags[i]){
            for(int j = i; j <= N; j+=i){
                if(!flags[j]){
                    cnt++;
            		flags[j] = 1;
                }
                if(cnt == K){
                    ans = j;
                    cout << ans << endl;
    				return 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}