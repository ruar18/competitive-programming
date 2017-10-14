#include <iostream>
#include <stack>
using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	stack<string> s;
	string curr, thing="", dir="";
	cin >> curr;
	while(curr != "SCHOOL")
	{
		s.push(curr);
		cin >> curr;
	}
	while(!s.empty()){
		curr = s.top();
		s.pop();
		dir = curr == "R"? "LEFT" : "RIGHT";
		if(s.empty()){
			cout << "Turn " << dir << " into your HOME." << '\n';
			return 0;
		}
		thing = s.top();
		s.pop();
		cout << "Turn " << dir << " onto " << thing << " street." << '\n';
	}
}