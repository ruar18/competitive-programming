#include <iostream>

using namespace std;

int main()
{
    float a, b, c, A=0, B=0;
    cin >> a >> b >> c;

    if (a > 100){
        A += (a-100)*0.25;
    }
    A += b * 0.15;
    A += c * 0.20;

    if (a > 250){
        B += (a-250)* 0.45;
    }
    B += b * 0.35;
    B += c * 0.25;

    cout << "Plan A costs " << A << endl;
    cout << "Plan B costs " << B << endl;

    if (B > A)
        cout << "Plan A is cheapest.";
    else if ((A - B) > 0)
        cout << "Plan B is cheapest.";
    else
        cout << "Plan A and B are the same price.";



    return 0;
}