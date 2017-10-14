#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> people;
    int n;
    cin >> n;
    for(int i = 0; i < 2 * n - 1; i++)
    {
        string name;
        cin >> name;
        if(people.find(name) == people.end())
            people.insert(name);
        else people.erase(name);
    }
    cout << *people.begin();
    return 0;
}