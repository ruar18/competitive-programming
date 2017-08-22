#include <iostream>
#include <stack>
#include <string>
using namespace std;

void convert(string s){
    stack<char> op;
    string res;
    for(int i = s.length()-1; i >= 0; i--){
        if(s[i] == ' ' || s[i] == '\n')
            continue;
        if(isdigit(s[i]))
            op.push(s[i]);
        else if(s[i] == '+' || s[i] == '-'){
            if(op.empty()) {
                res += s[i];
                break;
            }
            char op1 = op.top(); op.pop();
            char op2 = op.top(); op.pop();
            if(op1 != 'p' && op2 != 'p'){
                string temp = {op1, op2, s[i]};
                res = temp + res;
                op.push('p');
                continue;
            }
            if(op1 != 'p') res = op1 + res;
            if(op2 != 'p') res += op2;
            res += s[i];
            op.push('p');
        }
    }
    while(!op.empty())
    {
        if(op.top() != 'p') res += op.top();
        op.pop();
    }
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}

int main(){
    string line;
    getline(cin, line);
    while(line != "0"){
        convert(line);
        getline(cin, line);
    }
}