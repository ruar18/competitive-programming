#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool flags[31623];
vector<int> primes;

void sieve(int n){
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(!flags[i]){
            primes.push_back(i);
            for(int j = i*i; j<=sqrt(n); j+=i)
                flags[j] = 1;
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int Y;
    cin >> Y;
    sieve(Y);
    for(int i = 0; i < primes.size(); i++){
        while(Y%primes[i] == 0){
            cout << primes[i] << '\n';
            Y/=primes[i];
        }
    }
    if(Y!=1) cout << Y << '\n';
    return 0;
}