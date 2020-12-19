#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, m, k;
int p[MAXN];
bool isVisited[MAXN];
vector<vi> v;

void dfs(int i) {
    isVisited[i]=true;
    for(auto val: v[i]) {
        if(isVisited[val]) {
            print(i, val);
            return;
        }
        else {
            p[val]=i;
            dfs(val);
        } 
    }
}

int main() {
    cin >> n >> m;
    v.resize(n+1);

    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    i//for(int i=1; i<=n; i++) p[i]=i; 
    for(int i=1; i<=n; i++) {
        if(!isVisited[i]) {
            if(bfs(i)) return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}   
