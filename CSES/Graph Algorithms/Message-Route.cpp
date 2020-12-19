#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, m;
int parent[MAXN];
bool isVisited[MAXN];
vector<vi> v;

void print() {
    int node=n;
    stack<int> s;
    while(node!=1) {
        s.push(node);
        node=parent[node];
    }
    s.push(1);
    cout << s.size() << endl;
    while(!s.empty()) {
        cout << s.top() << " "; 
        s.pop();
    }
}

void bfs() {
    queue<int> q;
    q.push(1);
    isVisited[1]=true;
    while(!q.empty()) {
        int node=q.front(); q.pop();
        if(node==n) {
            print();
            return;
        }
        for(auto child: v[node]) {
           if(!isVisited[child]) {
                isVisited[child]=true;
                parent[child]=node;
                q.push(child);
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
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
    
    bfs();

    return 0;
}
