#include <bits/stdc++.h>
using namespace std;

int n, x, y, minx=10000, maxy=0, miny=10000, maxx=0;
pair<int, int> points[101];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        points[i]=make_pair(x,y);
        if(x<minx) minx=x;
        if(x>maxx) maxx=x;
        if(y>maxy) maxy=y;
        if(y<miny) miny=y;
    }
    int maxdist=0;
    pair<int, int> p1, p2;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(abs(points[i].first-points[j].first)>maxdist)maxdist=abs(points[i].first-points[j].first);
            if(abs(points[i].second-points[j].second)>maxdist)maxdist=abs(points[i].second-points[j].second);
        }
    }
    printf("%d", (int)maxdist*maxdist);
    return 0;
}