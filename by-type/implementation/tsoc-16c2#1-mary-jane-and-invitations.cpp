#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, cnt;
string s, name;
vector<char> types;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin.ignore();
    cin >> s;
    // cout << "good\n";
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='X'){
            cnt=1;
            // cout << "sup: " << i << '\n';
            while(i<s.size()-1&&s[++i]=='X') cnt++;
            types[types.size()-cnt]=s[i];
            // cout << i << '\n';
        }
        else types.push_back(s[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> name;
        if(types[i]=='A') cout << "Dear " << name << ", beloved artist, I would love to have you at my party. Come to my crib on April 20th.\n";
        else if(types[i]=='O') cout << "Dear " << name << ", beloved occasion enthusiast, come to my crib to celebrate this very special day.\n";
        else cout << "Dear " << name << ", April 20th is happening again this year. Don't miss out.\n";
    }
}
