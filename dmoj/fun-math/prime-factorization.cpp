#include <iostream>
#include <math.h>
using namespace std;


bool isPrime(int n){
    if(n < 2)
        return false;
    else if(n == 2 || n == 3)
        return true;
    else if(n % 2 == 0 || n % 3 == 0)
        return false;
    else{
        int fac = 5, lim = floor(sqrt(n));
        for(; fac <= lim; fac+=6)
        {
            if(n % fac == 0 || n % (fac+2) == 0)
                return false;
        }
        return true;
    }
}

void printFac(int n){
    if(isPrime(n)){
        cout << n << endl;
        return;
    }
    else if(n % 2 == 0)
    {
        cout << 2 << ' ';
        printFac(n / 2);
        return;
    }
    else if(n % 3 == 0)
    {
        cout << 3 << ' ';
        printFac(n / 3);
        return;
    }
    int fac = 5, lim = floor(sqrt(n));
    for(; fac <= lim; fac += 6){
        if(n % fac == 0)
        {
            cout << fac << ' ';
            printFac(n / fac);
            return;
        }
        else if(n % (fac+2) == 0)
        {
            cout << fac + 2 << ' ';
            printFac(n / (fac+2));
            return;
        }
    }

}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        printFac(m);
    }
    return 0;
}
