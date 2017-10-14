#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

vector<int> courses;
int main()
{
	int C, N;
	scanf("%i%i", &C, &N);
	int sum = 0;
	for (int i = 0; i < C; i++) {

		string val;
		cin >> val;
		if (val == "TOK") {
			courses.push_back(1);
			continue;
		}
		else if (val == "English") {
			courses.push_back(2);
			continue;
		}
		else if (val == "Chemistry") {
			courses.push_back(3);
			continue;
		}
		else {
			courses.push_back(4);
			continue;
		}
	}


	sort(courses.begin(), courses.end());
	int counter = 0;
	for (int i = 0; i < C; i++) {
		sum += courses[i];
		if (sum > N) {
			cout << "Go to Metro" << '\n' << counter;
			return 0;
		}
		else if (sum <= N && i == C - 1) {
			cout << "YEA BOI";
			return 0;
		}
		counter++;
	}
    return 0;
}