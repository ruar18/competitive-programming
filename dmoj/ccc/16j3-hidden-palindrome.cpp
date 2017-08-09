#include <iostream>
#include <string>
using namespace std;

bool isPal(string s){
    if(s.length() == 0 || s.length() == 1)
        return 1;
    else if(s[0] == s[s.length()-1])
        return isPal(s.substr(1, s.length()-2));
    return 0;
}

int main()
{
    string s;
    cin >> s;
    int longest = 1;
    for(int i = 0; i < s.length(); i++){
        for(int j = i ; j <= s.length(); j++){
            int length = j - i;
            if(isPal(s.substr(i, length))){
                if(length > longest)
                    longest = length;
            }
        }
    }
    cout << longest << endl;
    return 0;
}