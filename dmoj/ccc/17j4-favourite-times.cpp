#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool isArith(int t[4]){
    return t[0] == 0? t[2] - t[1] == t[3] - t[2] : t[1] - t[0] == t[2] - t[1] && t[2] - t[1] == t[3] - t[2];
}

int main()
{
    int d;
    scanf("%d", &d);
    int t[4] = {1,2,0,0};
    int ans = 0;
    for(int i = 0; i < d && i < 720; i++){
        // increase
        t[3]++;
        // fix right side of time
        if(t[3] > 9)
            t[2]++;
        t[3]%=10;
        // fix left side
        if(t[2] * 10 + t[3] > 59){
            t[1]++;
            t[2] = t[3] = 0;
        }
        int left = t[0] * 10 + t[1];
        if(left == 10){
            t[0] = 1;
            t[1] = 0;
            ans += isArith(t);
            continue;
        }
        if(left!=12){
            if(left < 12){
                ans += isArith(t);
                continue;
            }
            left %= 12;
            t[1] = (left%=10);
        }
        t[0] = left == 0? 1:left/10;
        ans += isArith(t);
    }
    if(d <= 720){
        printf("%d\n", ans);
        return 0;
    }
    ans *= (d/720);
    d %= 720;
    for(int i = 0; i < d; i++){
        // increase
        t[3]++;
        // fix right side of time
        if(t[3] > 9)
            t[2]++;
        t[3]%=10;
        // fix left side
        if(t[2] * 10 + t[3] > 59){
            t[1]++;
            t[2] = t[3] = 0;
        }


        int left = t[0] * 10 + t[1];
        if(left == 10){
            t[0] = 1;
            t[1] = 0;
            ans += isArith(t);
            continue;
        }
        if(left!=12){
            if(left < 12){
                ans += isArith(t);
                continue;
            }
            left %= 12;
            t[1] = (left%=10);
        }
        t[0] = left == 0? 1:left/10;
        ans += isArith(t);
    }
    printf("%d\n", ans);
    return 0;
}
