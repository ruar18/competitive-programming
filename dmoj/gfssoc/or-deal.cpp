#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    long long n;
    cin >> n;
    while(n>0){
        cout << "1";
        n>>=1;
    }
    return 0;
}