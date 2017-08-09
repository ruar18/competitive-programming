#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int k, a;
    vector<int> arr;
    cin >> k;
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        if(a == 0){
            arr.pop_back();
        }
        else{
            arr.push_back(a);
        }
    }
    a = 0;
    for(int i = 0; i < arr.size(); i++){
        a += arr[i];
    }
    cout << a;
    return 0;
}