#include <iostream>

using namespace std;

int main()
{
    int w;
    cin >> w;
    int c;
    cin >> c;
    if(w == 3 && c >= 95){
        cout << "C.C. is absolutely satisfied with her pizza.";
    }
    else if(w == 1 && c <= 50){
        cout << "C.C. is fairly satisfied with her pizza.";
    }
    else{
        cout << "C.C. is very satisfied with her pizza.";
    }
    return 0;
}