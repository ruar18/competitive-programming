#include <iostream>

using namespace std;

int main()
{
    int currentYear;
    int futureYear;
    cin >> currentYear;
    cin >> futureYear;
    for(currentYear; currentYear <= futureYear; currentYear += 60){
        cout << "All positions change in year " << currentYear << endl;
    }
    return 0;
}