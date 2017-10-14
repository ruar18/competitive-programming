#include <iostream>

using namespace std;

int main()
{
    int wins = 0;
    char state;
    for(int i = 0; i < 6; i++){
        cin >> state;
        if(state == 'W')
            wins++;
    }
    if(wins >= 5)
        cout << 1 << endl;
    else if(wins >= 3 )
        cout << 2 << endl;
    else if(wins >= 1)
        cout << 3 << endl;
    else
        cout << -1 << endl;
    return 0;
}