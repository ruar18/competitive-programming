#include <iostream>
using namespace std;

int main(){
	double w, h;
    cin >> w >> h;
    double bmi = w/(h*h);
    if(bmi > 25)
        cout << "Overweight" << endl;
    else if(bmi >= 18.5)
        cout << "Normal weight" << endl;
    else
        cout << "Underweight" << endl;
    return 0;
}
