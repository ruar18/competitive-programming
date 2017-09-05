#include <iostream>
using namespace std;

int main(){
	int a, b, c, d, sum=0;
    cin >> a >> b >> c >> d;
    int w[4] = {461, 431, 420, 0};
    int x[4] = {100, 57, 70, 0};
    int y[4] = {130, 160, 118, 0};
    int z[4] = {167, 266, 75, 0};
    sum = w[a-1] + x[b-1] + y[c-1] + z[d-1];
    cout << "Your total Calorie count is " << sum << "." << endl;
    return 0;
}
