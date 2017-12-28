#include <bits/stdc++.h>
using namespace std;

int a, b, n, m, adj[1001][1001], bonds[1001], numcarbon, numhydro, energy;

int main(){
    scanf("%d%d", &n,&m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        adj[a][b]++; adj[b][a]++;
        if(adj[a][b]>2){printf("Impossible"); return 0;}
        bonds[a]++; bonds[b]++;
        if(bonds[a]>4 || bonds[b]>4) {printf("Impossible"); return 0;}
    }
    for(int i = 1; i <= n; i++){
        if(bonds[i]==4) numcarbon++;
        else if(bonds[i]==1) numhydro++;
        else {printf("Impossible"); return 0;}
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(bonds[i]==4 && adj[i][j]==1){
                if(bonds[j]==4) energy+=346;
                else energy+=826;
            }
            else if(bonds[i]==4 && adj[i][j]==2){
                if(bonds[j]==4) energy+=615;
            }
            // H-H bond
            if(bonds[i]==1 && adj[i][j]==1 && bonds[j]==1){printf("Impossible"); return 0;}
        }
    }
    printf("%d\n", energy/2);
    if(numcarbon==1) printf("C");
    else printf("C%d", numcarbon);
    if(numhydro==1) printf("H");
    else printf("H%d", numhydro);
    return 0;
}
