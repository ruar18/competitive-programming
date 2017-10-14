#include <iostream>
#include <cmath>
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    long long a=0,b=0;
    string as="", bs="";
    cin >> as >> bs;
    for(int i = 0;i<as.length(); i++){
        if(isdigit(as[i])) a+=(as[i]-'0')*pow(16,as.length()-i-1);
        else a+=(tolower(as[i])-'a'+10)*pow(16,as.length()-i-1);
    }
    for(int i = 0;i<bs.length(); i++){
        if(isdigit(bs[i])) b+=(bs[i]-'0')*pow(16,bs.length()-i-1);
        else b+=(tolower(bs[i])-'a'+10)*pow(16,bs.length()-i-1);
    }
    if(a+b>1061109567)cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';
    return 0;
}
