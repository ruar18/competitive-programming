#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

int opn[256], cls[256], mx, tot, sum, temp;
bool f;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	for(int k = 0; k < 5; k++){
		string s;
		getline(cin, s);
		if(s.length() <= 2){
			cout << 0 << " " << atoi(s.c_str()) << '\n';
			continue;
		}
		for(int i = 1; i < s.length(); i++){
			opn[i]=opn[i-1], cls[i]=cls[i-1];
			if(s[i-1]=='(') opn[i]++;
			if(s[i-1]==')') cls[i]++;
			if(s[i]=='(') tot++;
			if(isdigit(s[i]) && !f){
				tot++;
				f=1;
				temp = s[i] - '0';
			}
			else if(f) {
				if(isdigit(s[i])){
					temp*=10;
					temp += (s[i]-'0');
				}
				sum += temp;
				temp = 0;
				f=0;
			}
		}
		for(int i = 0; i < s.length(); i++)
			if(opn[i] - cls[i] >= mx) mx=opn[i]-cls[i];
		cout << mx + (tot-mx)*2 << " " << sum << '\n';
		memset(opn, 0, sizeof(opn));
		memset(cls, 0, sizeof(cls));
		mx=tot=sum=temp=f=0;
	}

	return 0;
}