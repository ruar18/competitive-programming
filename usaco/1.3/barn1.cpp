/*
ID: rudyal11
PROG: barn1
LANG: C++11
*/

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout("barn1.out");
    ifstream fin("barn1.in");
    // max boards, #of stalls, #of occupied stalls
    int m, s, c, cnt=0, corig=0;
    fin >> m >> s >> c;
    corig = c;
    // first int: stall nu, second int: number seen so far
    vector<pair<int,int> > stalls;
    int prev;
    fin >> prev;
    stalls.push_back(make_pair(prev, 1));
    c--;
    int sum = 1;
    // read in stall nums
    while(c--)
    {
        int cur;
        fin >> cur;
        sum += cur - prev;
        stalls.push_back(make_pair(cur, sum));
        prev = cur;
    }
    if(m >= corig){
        fout << corig << endl;
        return 0;
    }
    sort(stalls.begin(), stalls.end());
    // First int: gap between last board and current. 2nd: index of stall after the gap
    multimap<int,int, greater<int> > gaps;
    for(int i = stalls.size()-1; i > 0; i--)
    {
        int gap = stalls[i].first - stalls[i-1].first;
        gaps.insert(make_pair(gap, i));

    }
    gaps.insert(make_pair(0, 0));
    vector<int> indices;
    int i = 1;
    for(multimap<int,int>::iterator it = gaps.begin(); it != gaps.end() && i < m; i++, ++it){
        indices.push_back(it->second);
    }
    sort(indices.begin(), indices.end());
    int bot = 0, total = 0;
    if(indices.size() == 0)
    {
        fout << stalls[stalls.size()-1].first - stalls[0].first+1 << endl;
        return 0;
    }
    for(int i = 0; i < indices.size();i++)
    {
        int diff = stalls[indices[i]-1].first - stalls[bot].first;
        bot = indices[i];
        total += diff + 1;
    }
    total += stalls[stalls.size()-1].first - stalls[indices[indices.size()-1]].first + 1;
    fout << total << endl;
    return 0;
}
