#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y, ans;
vector< vector<int>> g;
vector<bool> visited;

void solve(int i, int &cur) {
    cur++;
    visited[i]=true;

    for(auto v: g[i]) {
        if(!visited[v]) {
            solve(v, cur);
        }
    }
}

int main() {
    cin >> t;
    
    while(t--) {
        ans=0;
        g.clear();
        visited.clear();

        cin >> n >> m;
        g.resize(n+1);
        visited.resize(n+1,false);

        while(m--) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        for(int i=1; i<=n; i++) {
            if(!visited[i]) {
                int val=0;
                solve(i,val);
                ans=max(ans,val);     
            }
        }        
        cout << ans << endl;
    }
    return 0;
}
