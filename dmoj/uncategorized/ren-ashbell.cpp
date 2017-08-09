#include <iostream>

using namespace std;

int main()
{
    int n, power;
    cin >> n;
    n--;
    cin >> power;
    while(n--){
        int temp;
        cin >> temp;
        if(temp >= power){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
