#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

typedef struct {
    int to, cost;
} Edge;

int n, e, t, m, cnt=0;
vector<vector<Edge>> g;
vector<int> dist;

auto compare = [](int lhs, int rhs) {
    return dist[lhs] < dist[rhs];
};
 
priority_queue<int, vector<int>, decltype(compare)> heap(compare);

void dijkstra() {
    dist[e]=0;
    heap.push(e);

    while(!heap.empty()) {
        int cur=heap.top();
        heap.pop();

        for(auto e: g[cur]) {
            if(dist[e.to] > dist[cur] + e.cost) {
                dist[e.to] = dist[cur] + e.cost;
                heap.push(e.to);
            }
        }
    }
}

int main() {
    cin >> n >> e >> t >> m;
    g.resize(n+1);
    dist.resize(n+1, INF);
    for(int i=0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[y].push_back({x,z});
    }

    dijkstra();

    for(int i=1; i<=n; i++) {
        if(dist[i]<=t) cnt++;
    } 
    cout << cnt << endl;
    return 0;
}
