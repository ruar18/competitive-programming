#include <iostream>

using namespace std;

int main()
{
    int square[4][4];
    for(int i = 0; i < 4;i++){
        for(int j = 0; j < 4; j++)
            cin >> square[i][j];
    }
    int sum = 0;
    // establish a baseline
    for(int j = 0; j < 4; j++)
        sum += square[0][j];
    for(int i = 1; i < 4; i++){
        int temp = 0;
        for(int j = 0; j < 4; j++)
            temp += square[i][j];
        if(temp != sum)
        {
            cout << "not magic" << endl;
            return 0;
        }
    }
    cout << "magic" << endl;
    return 0;
}