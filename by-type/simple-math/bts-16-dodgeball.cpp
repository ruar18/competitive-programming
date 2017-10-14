#include <iostream>
using namespace std;

string names[100001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, prev = 0;
    unsigned long long cnt = 0;
    cin >> N;
    char prevFirst;
    for(int i = 0; i < N; i++)
        cin >> names[i];

    prevFirst = names[0][0];
    bool last = false;
    for (int i = 0; i < N; i++) {
        if(names[i][0] == prevFirst || names[i][0] == toupper(prevFirst))
            prev++;
        else{
            if(i == N-1){
                cnt++;
                last = 1;
            }

            cnt += (prev*(prev+1))/2;

            prevFirst = names[i][0];
            prev = 1;
        }
    }
    if(!last){
        cnt += (prev*(prev+1))/2;
    }

    cout << cnt;
    return 0;
}