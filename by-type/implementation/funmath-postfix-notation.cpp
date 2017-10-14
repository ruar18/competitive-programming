#include <iostream>
#include <stack>
#include <math.h>
#include <iomanip>

using namespace std;
int main() {
    stack<double> s;
    string curr;
    string line;
    while(cin >> curr){
        if(curr == "*"){
            double op2 = s.top();
            s.pop();
            double op1 = s.top();
            s.pop();
            s.push((op1 * op2));
        }
        else if(curr == "/"){
            double op2 = s.top();
            s.pop();
            double op1 = s.top();
            s.pop();
            s.push((op1 / op2));
        }
        else if(curr == "+"){
            double op2 = s.top();
            s.pop();
            double op1 = s.top();
            s.pop();
            s.push((op1 + op2));
        }
        else if(curr == "-"){
            double op2 = s.top();
            s.pop();
            double op1 = s.top();
            s.pop();
            s.push((op1 - op2));
        }
        else if(curr == "%"){
            double op2 = s.top();
            s.pop();
            double op1 = s.top();
            s.pop();
            s.push(fmod(op1, op2));
        }
        else if(curr == "^"){
            double op2 = s.top();
            s.pop();
            double op1 = s.top();
            s.pop();
            s.push(pow(op1, op2));
        }
        else{
            s.push(atoi(curr.c_str()));
        }

    }
    cout << fixed << setprecision(1) << s.top() << endl;
    return 0;
}