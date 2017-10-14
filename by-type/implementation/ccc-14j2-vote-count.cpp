#include <iostream>
using namespace std;

int main(){
	int a=0, b=0,v;
    char c='.';
    cin >> v;
    while(v--){
        cin>>c;
        if(c=='A')
            a++;
        else
            b++;
    }
    if(a==b)
        cout << "Tie" << endl;
    else if(a>b)
        cout << "A" << endl;
    else
        cout << "B" << endl;
    return 0;
}
