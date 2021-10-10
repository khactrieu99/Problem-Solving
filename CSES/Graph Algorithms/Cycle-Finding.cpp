#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

typedef struct {
    int a, b;
    long long cost;
} Edge;

typedef pair<int,int> pi;
typedef vector<pi> vp;

int n, m;
vector<Edge> g;

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c; 
        cin >> a >> b >> c;
        g.push_back({a, b, c});
    }    
    vector<long long> d(n+1);    
    vector<int> p(n+1, -1);

    int x=-1;
    for(int i=0; i<n; i++) {
        x=-1;
        for(auto e: g) {
            if(d[e.b] > d[e.a] + e.cost) {
                d[e.b] = d[e.a] + e.cost;
                    p[e.b] = e.a;
                    x = e.b;
            }
        }
    }

    if(x==-1) cout << "NO" << endl;
    else {
        for(int i=0; i<n; i++) x = p[x];
        vector<int> path;
        for(auto cur=x;;cur=p[cur]) {
            path.push_back(cur);
            if(cur==x && path.size() > 1) break;
        }
        reverse(path.begin(),path.end());

        cout << "YES" << endl;
        for(auto v: path) cout << v << " ";
        cout << endl;
    }
    
    return 0;
}
