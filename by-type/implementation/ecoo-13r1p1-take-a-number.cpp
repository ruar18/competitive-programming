#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    string a;
    cin >> a;
    int late = 0, served = 0, nextN = N;
    while(a != "EOF")
    {
        if(a == "TAKE")
        {
            nextN = nextN == 999? 1 : nextN+1;
            late++;
        }
        else if(a == "SERVE")
        {
            served++;

        }
        else if(a == "CLOSE")
        {
            printf("%d %d %d\n", late, late-served, nextN);
            late = served = 0;
        }
        cin >> a;
    }
    return 0;
}