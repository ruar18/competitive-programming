/*
ID: rudyal11
PROG: dualpal
LANG: C++11
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool isPalindrome(string s)
{
    if(s.length() == 0 || s.length() == 1)
        return true;
    else if(s[0] == s[s.length()-1])
        return isPalindrome(s.substr(1,s.length()-2));
    else
        return false;
}

// Converts n (in base 10) to the given base b
string toBase(int n, int b)
{
    string res = "";
    while(n > 0)
    {
        char next = '0' + n%b;
        res = next + res;
        n /= b;
    }
    return res;
}
int main()
{
    ofstream fout("dualpal.out");
    ifstream fin("dualpal.in");
    int N, S, found = 0, thisTime = 0;
    fin >> N >> S;
    S++;
    while(found < N)
    {
        thisTime = 0;
        for(int b = 2; b <= 10; b++)
        {
            if(isPalindrome(toBase(S, b)))
                thisTime++;
        }
        if(thisTime >= 2)
        {
            found++;
            fout << S << endl;
        }
        S++;
    }
    return 0;
}
