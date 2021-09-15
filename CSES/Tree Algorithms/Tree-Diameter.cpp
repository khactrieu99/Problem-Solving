#include <bits/stdc++.h>
using namespace std;

int n, head, max_dis=0;
vector<vector<int>> tree;
vector<bool> visited;

void findFarthest(int ver, int distance) {
    if(tree[ver].size()==1&&visited[tree[ver][0]]) {
        if(distance>max_dis) {
            max_dis=distance;
            head=ver;
        }
        return;
    }

    visited[ver]=true;
    for(auto v: tree[ver]) 
        if(!visited[v]) findFarthest(v, distance+1);
    visited[ver]=false;
}

int main() {
    cin >> n;
    tree.resize(n+1);
    visited.resize(n+1,false);
    for(int i=0; i<n-1; i++) {
        int x, y; cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    
    findFarthest(1,0);
    findFarthest(head,0);
    cout << max_dis << endl;

    return 0;
}
