/*
ID: rudyal11
PROG: milk
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main()
{
    // Note: this program can also be implemented with an array. Each index reps. price/unit, and we add the supplies to the indices
    // and just traverse the array. It's a much better implementation that I didn't think of.
    ofstream fout("milk.out");
    ifstream fin("milk.in");
    int n, m;
    fin >> n >> m;
    if(n == 0){
        fout << 0 << endl;
        return 0;
    }
    multimap<int, int> farmers;
    for(int i = 0; i < m; i++){
        int p, a;
        fin >> p >> a;
        farmers.insert(make_pair(p,a));
    }
    int price = 0, bought = 0;
    for(multimap<int,int>::iterator it = farmers.begin(); it != farmers.end(); ++it)
    {
        if(it->second > n - bought)
        {
            int diff = n-bought;
            bought = n;
            price += it->first * diff;
        }
        else{
            bought += it->second;
            price += it->first * it->second;
        }

        if(bought >= n)
        {
            fout << price << endl;
            return 0;
        }
    }
    return 0;
}
