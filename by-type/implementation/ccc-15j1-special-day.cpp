#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a;
    cin >> b;

    if (b == 18 && a == 2){
        cout << "Special" << endl;
    }
    else if(a < 2){
        cout << "Before" << endl;
    }
    else if (a == 2 && b < 18){
        cout << "Before" << endl;
    }
    else if(a == 2 && b > 18){
        cout << "After" << endl;
    }
    else{
        cout << "After" << endl;
    }
    return 0;
}