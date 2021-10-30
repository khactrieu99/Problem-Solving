#include<bits/stdc++.h>
using namespace std;

string s;
vector<vector<int>> g;
vector<vector<int>> a;
vector<int> p;
vector<bool> visited;
vector<int> ans;

void bfs() {
    queue<int> q;
    p.resize(s.size()+1);
    q.push(1);
    visited[1]=true;
    
    while(!q.empty()) {
        int cur=q.front(); q.pop();
        if(cur==s.size()) break;
        
        for(auto next: g[cur]) {
            if(!visited[next]) {
                q.push(next);
                p[next]=cur;
                visited[next]=true;
            }
        }
    }

    int cur=s.size();
    while(cur!=1) {
        ans.push_back(cur);
        cur=p[cur];
    }
    cout << ans.size() << endl;
}

int main() {
    cin >> s;
    a.resize(10);
    g.resize(s.size()+1);
    visited.resize(s.size()+1, false);

    for(int i=1; i<=s.size(); i++) {
        a[s[i-1]-'0'].push_back(i);
    }
    for(int i=0; i<=9; i++) {
        if(a[i].size() >= 2) {
            int last=a[i].size()-1;

            g[a[i][0]].push_back(a[i][last]);
            g[a[i][last]].push_back(a[i][last]-1);

            if(a[i][last]+1 <= s.size()) {
                g[a[i][last]].push_back(a[i][last]+1);
            }
        } else if(a[i].size() == 1) {
            if(a[i][0] - 1 > 0) {
                g[a[i][0]].push_back(a[i][0]-1);
            }
            
            if(a[i][0] + 1 <= s.size()) {
                g[a[i][0]].push_back(a[i][0]+1);
            }
        }
    }

    bfs();
    return 0;
}
