#include <bits/stdc++.h>
using namespace std;

int n;
map<int, vector<int>> tree;
vector<vector<int>> dp;
vector<bool> visited;

int process(int node, int state) {
    int res=0, temp=0;
    visited[node]=true;
    
    for(auto v: tree[node]) {
        if(!visited[v]) {
            if(dp[v][0]==-1) dp[v][0]=process(v,0);
            if(dp[v][1]==-1) dp[v][1]=process(v,1);

            temp+=max(dp[v][0],dp[v][1]);
        }
    }

    if(state==0) res=temp;
    else {
        temp+=1;

        for(auto v: tree[node]) {
            if(!visited[v])
                res=max(res,temp-max(dp[v][0],dp[v][1])+dp[v][0]);
        }   
    }

    visited[node]=false; 
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; 

    dp.resize(n+1, vector<int>(2, -1));   
    visited.resize(n+1, false);

    for(int i=0; i<n-1; i++) {
        int x, y; cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    cout << max(process(1,0), process(1,1)) << endl;

    return 0;
}
