#include <bits/stdc++.h>
using namespace std;

const long long INF = -1e15;

typedef struct {
    int des;
    long long cost;
} edge;

int n, m, x, y, c;
vector<vector<edge>> g, revG;
vector<long long> dist;
vector<bool> vis1, vis2;
vector<int> vertice;
vector<int> change;

void dfs1(int i) {
    vis1[i]=true;
    
    for(auto next: g[i]) {
        if(!vis1[next.des]) dfs1(next.des);
    }
}

void dfs2(int i) {
    vis2[i]=true;
    
    for(auto next: revG[i]) {
        if(!vis2[next.des]) dfs2(next.des);
    }
}

int main() {
    cin >> n >> m;
    dist.resize(n+1, INF);
    vis1.resize(n+1, false);
    vis2.resize(n+1, false);
    g.resize(n+1);
    revG.resize(n+1);

    while(m--) {
        cin >> x >> y >> c;
        g[x].push_back({y, c});
        revG[y].push_back({x, c});
    }

    dist[1]=0;
    for(int i=0; i<n; i++) {
        change.clear();
        for(int v=1; v<=n; v++) {
            for(auto e: g[v]) {
                if(dist[e.des]<dist[v]+e.cost) {
                    dist[e.des]=dist[v]+e.cost;
                    change.push_back(e.des);
                }
            }
        }
    }        
    
    if(!change.empty()) {
        dfs1(1); dfs2(n);
        for(auto i: change) {
            if(vis1[i] && vis2[i]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    cout << dist[n] << endl;
    return 0;
}   
