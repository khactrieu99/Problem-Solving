#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, m;
vector<int> color;
vector<vi> v;

void print() {
    for(int i=1; i<=n; i++) cout << color[i] << " ";
    cout << endl;
}

bool bfs(int i) {
    queue<int> q;
    color[i]=1;
    q.push(i);
    while(!q.empty()) {
        int s=q.front(); q.pop();
        int cl=color[s]%2+1;
        for(auto val: v[s]) {
            if(color[val]==-1) {
                color[val]=cl;
                q.push(val);
            }
            else if(color[val]!=cl) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    color.resize(n+1, -1);
    v.resize(n+1);

    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for(int i=1; i<=n; i++) {
        if(color[i]==-1) {
            if(!bfs(i)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    print();

    return 0;
}
