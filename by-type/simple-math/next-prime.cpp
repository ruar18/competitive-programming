#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n){
    if(n == 1)
        return false;
    else if(n < 4)
        return true;
    else if(n % 2 == 0)
        return false;
    else if(n<9)
        return true;
    else if(n%3==0)
        return false;
    else{
        int lim = floor(sqrt(n));
        int factor = 5;
        while(factor<=lim){
            if(n%factor==0)
                return false;
            if(n%(factor+2)==0)
                return false;
            factor+=6;
        }
    }
    return true;
}
int main()
{
    int N;
    cin >> N;
    if(isPrime(N)){
        cout << N;
        return 0;
    }

    while(!isPrime(++N));
    cout << N;
    return 0;
}