#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

int n, m, t, l, r;
vvi g;
vb visited;

bool solve(int v) {
    if(visited[v]) return true;
    visited[v]=true;
    for(auto i: g[v]) if(solve(i)) return true;
    return false;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        g.clear();
        visited.clear();

        g.resize(n+1);
        visited.resize(n+1, false);

        while(m--) {
            cin >> l >> r;
            g[l].push_back(r);
        }   
        
        bool flag = false;
        for(int i=1; i<=n; i++ ) {
            for(auto v: g[i]) {
                if(!visited[v]) {
                    flag = flag || solve(v);
                }
            }
        }
        if(flag) cout << "SIM" << endl;
        else cout << "NAO" << endl;
    }

    return 0;
}
