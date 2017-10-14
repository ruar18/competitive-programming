#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> list;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		int num;
		cin >> num;
		list.push_back(num);
	}

	sort(list.begin(), list.end());
	for (int i = 0; i < size; i++) {
		cout << list[i] << '\n';
	}

    return 0;