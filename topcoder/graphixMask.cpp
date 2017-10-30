#include <bits/stdc++.h>
using namespace std;

class grafixMask{
    bool vis[600][400];
    int X1, X2, Y1, Y2;
    int dfs(int x, int y){
        int temp=0;
        stack<pair<int,int>> st;
        st.push({x,y});
        while(!st.empty()){
            int curx=st.top().first, cury=st.top().second;
            st.pop();
            if(curx<0||curx>=400||cury<0||cury>=600) continue;
            vis[curx][cury]=1;
            temp++;
            st.push({x-1,y}); st.push({x+1,y});
            st.push({x,y+1}); st.push({x,y-1});
        }
        return temp;
    }
    public:
        vector<int> sortedAreas(vector<string> rectangles){
            vector<int> ans;
            // block off
            for(string s:rectangles){
                istringstream iss(s);
                iss >> X1 >> Y1 >> X2 >> Y2;
                for(int i = X1; i <= X2; i++){
                    for(int j = Y1; j<=Y2; j++){
                        vis[i][j]=1;
                    }
                }
            }
            for(int i = 0; i < 600; i++){
                for(int j = 0; j < 400; j++){
                    if(!vis[i][j]){
                        ans.push_back(dfs(i, j));
                    }
                }
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
};
