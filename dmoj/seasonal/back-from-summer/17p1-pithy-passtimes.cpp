#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, a=0;
    cin >> n;
    string t="";
    while(n--){
        cin>>t;
        if(t.size() <= 10)
            a++;
    }
    cout << a << endl;
	return 0;
}