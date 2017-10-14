#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, string> dict = {{"CU", "see you"}, {":-)", "I'm happy"}, {":-(", "I'm unhappy"}, {";-)", "wink"}, {":-P", "stick out my tongue"}, {"(~.~)", "sleepy"}, {"TA", "totally awesome"}, {"CCC", "Canadian Computing Competition"}, {"CUZ", "because"}, {"TY", "thank-you"}, {"YW", "you're welcome"}, {"TTYL", "talk to you later"}};

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    string s;
    while(cin >> s) {
        if(dict.count(s)==0) cout << s << '\n';
        else cout << dict[s] << '\n';
        if(s=="TTYL") break;
    }
    return 0;
}
