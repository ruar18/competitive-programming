#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

unordered_map<string, int> s;
int c, op, idx;
string cur;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> c;
    while(c--){
        cin >> op;
        if(op!=4) cin>>cur;
        if(op==1){
            if(s.count(cur)==0) {cout << "true\n"; s[cur]=idx++;}
            else cout << "false\n";
        }
        else if(op==2){
            if(s.count(cur)!=0) {cout << "true\n"; s.erase(cur);}
            else cout << "false\n";
        }
        else if(op==3){
            if(s.count(cur)==0) cout << "-1\n";
            else if(s.size()==1) cout << "0\n";
            else{
                if(cur=="true") cout << (s["false"]>s[cur]?"0":"1");
                else cout << (s["true"]>s[cur]?"0":"1");
            }
        }
        else{
            if(s.size()==2) cout << "false true";
            else for(pair<string, int> p : s) cout << p.first << " ";
            cout << '\n';
        }
    }

    return 0;
}
