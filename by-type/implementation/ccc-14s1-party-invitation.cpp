#include <cstdio>
using namespace std;

int party[101], k, m, cur, j;

int main(){
    scanf("%d%d", &k, &m);
    for(int i = 1; i <= k; i++)
        party[i]=i;
    party[0] = -1;
    while(m--){
        scanf("%d", &cur);
        j=0;
        for(int i = 1; i<=k; i++){
            if(party[i] != -1) j++;
            if(j%cur==0) {party[i]=-1; j=0;}
        }
    }
    for(int i = 1; i <= k; i++)
        if(party[i]!=-1) printf("%d\n", party[i]);
}
