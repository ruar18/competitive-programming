#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

unordered_map<int, int> x, y;
multiset<pair<int, int>> points;
int n, q, cx, cy, op;
char detop;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    while(n--){
        cin >> cx >> cy;
        x[cx]++; y[cy]++;
        points.insert(make_pair(cx, cy));
    }
    while(q--){
        cin >> op;
        if(op==1){
            cin >> cx >> cy;
            if(points.find(make_pair(cx, cy))!=points.end()) cout << "salty" << '\n';
            else cout << "bland" << '\n';
        }
        else{
            cin >> detop;
            if(detop=='X'){
                cin >> cx;
                cout << (x.count(cx)==0? 0:x[cx]) << '\n';
            }
            else{
                cin >> cy;
                cout << (y.count(cy)==0? 0:y[cy]) << '\n';
            }
        }
    }
    return 0;
}
