#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int m[6], previ=-1;
bool h[6];

void move(int from, int to){
    m[to]=m[from];
    m[from]=0;
    previ=to;
}
bool check(){
    int cnt=0;
    cnt=0;
    for(int i = 0; i < 6; i++){
        if(!h[i])cnt++;
        if(cnt>=1)
            return true;
    }
    return false;
}
int main() {
    int n, a=0, i=0, cnt=0;
    cin >> n;
    string t="", prev="";
    while(n--){
        cin>>t;
        if(t=="red")
            m[0]++;
        else if(t=="orange")
            m[1]++;
        else if(t=="yellow")
            m[2]++;
        else if(t=="green")
            m[3]++;
        else if(t=="blue")
            m[4]++;
        else if(t=="black")
            m[5]++;
    }
    sort(m, m+6, greater<int>());
    for(int i = 0; i < 2; i++){
        if(m[i]!=0)
        {
            a++;
            m[i]--;
            previ=i;
            if(i==1)i=-1;
            continue;
        }
        if(m[1]==0){
            move(0, 1);
            break;
        }
        if(m[0]==0) break;

    }
    bool f=previ==1;
    cnt=0;
    for(int i = 1; i < 3; i++){
        if(f){
            if(m[2]!=0){
                a++;
                m[2]--;
                previ=2;
            }
            else {
                move(1, 2);
                break;
            }
            f=0;
            i=0;
            continue;
        }
        if(m[i]!=0)
        {
            a++;
            m[i]--;
            previ=i;
            if(i==2)i=0;
            continue;
        }
        if(m[2]==0){
            move(1,2);
            break;
        }
        if(m[1]==0) break;

    }
    f=previ==2;
    cnt=0;
    for(int i = 2; i < 4; i++){
        if(f){
            if(m[3]!=0){
                a++;
                m[3]--;
                previ=3;
            }
            else {
                move(2,3);
                break;
            }
            f=0;
            i=1;
            continue;
        }
        if(m[i]!=0)
        {
            a++;
            m[i]--;
            previ=i;
            if(i==3)i=1;
            continue;
        }
        if(m[3]==0){
            move(2,3);
            break;
        }
        if(m[2]==0) break;

    }

    f=previ==3;
    cnt=0;
    for(int i = 3; i < 5; i++){
        if(f){
            if(m[4]!=0){
                a++;
                m[4]--;
                previ=4;
            }
            else {
                move(3,4);
                break;
            }
            f=0;
            i=2;
            continue;
        }
        if(m[i]!=0)
        {
            a++;
            m[i]--;
            previ=i;
            if(i==4)i=2;
            continue;
        }
        if(m[4]==0){
            move(3,4);
            break;
        }
        if(m[3]==0) break;

    }


    f=previ==4;
    cnt=0;
    for(int i = 4; i < 6; i++){
        if(f){
            if(m[5]!=0){
                a++;
                m[5]--;
                previ=5;
            }
            else {
                move(4,5);
                break;
            }
            f=0;
            i=3;
            continue;
        }
        if(m[i]!=0)
        {
            a++;
            m[i]--;
            previ=i;
            if(i==5)i=3;
            continue;
        }
        if(m[5]==0){
            move(4,5);
            break;
        }
        if(m[4]==0) break;

    }
    cout << a << endl;
    return 0;
}