#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;

int n, m;
vector<int> x;
vector<vector<ll>> ways;

int solve() {
    ll ans=0;
    ways.resize(m+2);
    for(auto &t: ways) {
        t=vector<ll>(n+1, 0);
    }
    
    if(x[0]==0) for(int i=1; i<=m; i++) ways[i][1]=1;
    else ways[x[0]][1]=1;
    
    for(int i=2; i<=n; i++) {
        if(x[i-1]!=0) ways[x[i-1]][i]=(ways[x[i-1]-1][i-1]%MOD+ways[x[i-1]][i-1]%MOD+ways[x[i-1]+1][i-1]%MOD)%MOD;
        else 
            for(int j=1; j<=m; j++) {
                ways[j][i]=(ways[j-1][i-1]%MOD+ways[j][i-1]%MOD+ways[j+1][i-1]%MOD)%MOD;
            }
    }
    for(int i=1; i<=m; i++) (ans+=ways[i][n])%=MOD;
    return ans;
}

int main() {
    cin >> n >> m;
    x.resize(n);
    for(auto &e: x) cin >> e;
    
    cout << solve() << endl;

    return 0;
}
