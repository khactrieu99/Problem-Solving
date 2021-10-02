#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<vector<char>> g;
vector<pair<int,int>> points;
vector<vector<bool>> visited;
vector<vector<bool>> pVisited;

void solve(int x, int y) {
    if(points.size()>0) { 
        if(x==points[0].first && y==points[0].second) {
            points.pop_back();
            return;
        }
        visited[x][y]=true;

        if(x+1<n && g[x+1][y]!='#' && !visited[x+1][y]) solve(x+1, y); 
        if(x-1>=0 && g[x-1][y]!='#' && !visited[x-1][y]) solve(x-1, y);
        if(y+1<m && g[x][y+1]!='#' && !visited[x][y+1]) solve(x, y+1);
        if(y-1>=0 && g[x][y-1]!='#' && !visited[x][y-1]) solve(x, y-1);
    }    
}

int main() {
    cin >> t;

    while(t--) {
        cin >> n >> m;
        
        g.clear();
        g.resize(n, vector<char>(m));
        
        visited.clear();
        visited.resize(n, vector<bool>(m, false));
        
        pVisited.clear();
        pVisited.resize(n, vector<bool>(m, false));
    
        for(auto &r: g) {
            for(auto &j: r) cin >> j;
        }
        
        for(int i=0; i<n; i++) {
            if(g[i][0]=='.' && !pVisited[i][0]) points.push_back(make_pair(i,0));
            if(g[i][m-1]=='.' && m-1!=0 && !pVisited[i][m-1]) points.push_back(make_pair(i,m-1));

            pVisited[i][0] = true;
            pVisited[i][m-1] = true;
        }
        for(int j=0; j<m; j++) {
            if(g[0][j]=='.' && !pVisited[0][j]) points.push_back(make_pair(0,j));
            if(g[n-1][j]=='.' && n-1!=0 && !pVisited[n-1][j]) points.push_back(make_pair(n-1,j));
        
            pVisited[0][j] = true;
            pVisited[n-1][j] = true;
        }
        
        if(points.size()!=2) cout << "invalid" << endl;
        else {
            pair<int,int> start = points[1];
            points.pop_back();

            solve(start.first, start.second);

            if(points.empty()) cout << "valid" << endl;
            else cout << "invalid" << endl;           
        }
    }
    
    return 0;
}
