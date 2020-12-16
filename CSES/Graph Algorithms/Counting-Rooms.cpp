#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<int,int> pii;

int n, m, components=0;
vector<vc> g;
vector<vb> isVisited;

void findConnectedComponent(int i, int j) {
    if(!isVisited[i][j]&&g[i][j]=='.') {
        isVisited[i][j]=true;
        findConnectedComponent(i+1,j);
        findConnectedComponent(i-1,j);
        findConnectedComponent(i,j+1);
        findConnectedComponent(i,j-1);
    }
}

int main() {
    cin >> n >> m;
    g.resize(n+2);
    isVisited.resize(n+2);
    for(int i=0; i<n+2; i++) {
        g[i].resize(m+2);
        isVisited[i].resize(m+2);
    }
    for(int i=0; i<n+2; i++) {
        for(int j=0; j<m+2; j++) {
            isVisited[i][j]=true;
            if(i>0&&j>0&&i<n+1&&j<m+1) {
                cin >> g[i][j];
                isVisited[i][j]=false;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(!isVisited[i][j]&&g[i][j]=='.') {
                findConnectedComponent(i,j);
                ++components;    
            }
        }   
    }   

    cout << components << endl;
    
    return 0;
}
