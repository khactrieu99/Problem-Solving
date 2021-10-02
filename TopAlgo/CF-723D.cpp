#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;

int n, m, k, ans=0;
vector<vc> g, tempG;
vector<vector<pii>> cnt;
vector<vb> visited; 
 
void find_connected(int i, int j) {
    visited[i][j]=true;
    cnt.back().push_back(make_pair(i,j));
    
    if(i-1>0&&tempG[i-1][j]=='.'&&!visited[i-1][j]) find_connected(i-1,j);
    if(i+1<n-1&&tempG[i+1][j]=='.'&&!visited[i+1][j]) find_connected(i+1,j);
    if(j-1>0&&tempG[i][j-1]=='.'&&!visited[i][j-1]) find_connected(i,j-1);
    if(j+1<m-1&&tempG[i][j+1]=='.'&&!visited[i][j+1]) find_connected(i,j+1);
}

void fill(int i, int j) {
    if(tempG[i][j]=='.') tempG[i][j]='*';
    
    if(i-1>0&&tempG[i-1][j]=='.') fill(i-1,j);
    if(i+1<n&&tempG[i+1][j]=='.') fill(i+1,j);
    if(j-1>0&&tempG[i][j-1]=='.') fill(i,j-1);
    if(j+1<m&&tempG[i][j+1]=='.') fill(i,j+1);
}

int main() {
    cin >> n >> m >> k;

    g.resize(n, vc(m));
    tempG.resize(n, vc(m));
    visited.resize(n, vb(m, false));    

    for(int i=0; i<n; i++) { 
        for(int j=0; j<m; j++) {
            char x; cin >> x;
            g[i][j]=x;
            tempG[i][j]=x;
        }
    }
        
    // fill the ocean
    for(int i=0; i<n; i++) {
        if(tempG[i][0]=='.') fill(i,0);
        if(tempG[i][m-1]=='.') fill(i,m-1);
    }
    for(int j=0; j<m; j++) {
        if(tempG[0][j]=='.') fill(0,j);
        if(tempG[n-1][j]=='.') fill(n-1,j);
    }    

    // find how many connected part there are
    for(int i=1; i<n-1; i++) {
        for(int j=1; j<m-1; j++) {
            if(tempG[i][j]=='.' && !visited[i][j]) {
                cnt.push_back(vector<pii>());
                find_connected(i,j);
            } 
        }
    }        
    
    sort(cnt.begin(),cnt.end(),[](const auto& l, const auto& r){
        return l.size() < r.size();
    });         
        
    for(int i=0; i<cnt.size()-k; i++) {
        for(auto v: cnt[i]) {
            int f=v.first, s=v.second;
            g[f][s]='*';
            ans++;
        }
    }    
    
    cout << ans << endl;
    for(auto r: g) {
        for(auto v: r) cout << v;
        cout << endl;
    } 

    return 0;
}
