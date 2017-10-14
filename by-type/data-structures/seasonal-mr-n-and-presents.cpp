#include <cstdio>
#include <unordered_map>
using namespace std;

int q;
int x;
char op;
int dq[200005], l=100000, r = 100000;
unordered_map<int, int> pos;
int main(){
    scanf("%d", &q);
    while(q--){
        scanf(" %c%d", &op, &x);
        if(op=='F') {dq[--l]=x; pos[x]=l;}
        else if(op=='E') {dq[++r]=x; pos[x]=r;}
        else {dq[pos[x]]=0; pos.erase(x); }
    }
    for(int i = l; i <= r; i++) if(dq[i]) printf("%d\n", dq[i]);
}
