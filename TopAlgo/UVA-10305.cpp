#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m;
vvi g;
vb visited;
stack<int> rs;

void dfs(int i) {
    visited[i]=true;
    for(auto j: g[i]) {
        if(!visited[j]) dfs(j);
    }    
    rs.push(i);
}

void solve() {
    for(int i=1; i<=n; i++) {
        if(!visited[i]) dfs(i);
    }
    
    while(!rs.empty()) {
        cout << rs.top() << " ";
        rs.pop();
    }
    cout << endl;
}

int main() {
    while(cin >> n >> m) {
        if(n!=0&&m!=0) {
            g.clear();
            g.resize(n+1);
            
            visited.clear();
            visited.resize(n+1, false);

            for(int i=0; i<m; i++) {
                int x, y;
                cin >> x >> y;
                g[x].push_back(y);
            }       
            solve();
        } else return 0;
    }    
    return 0;
}
