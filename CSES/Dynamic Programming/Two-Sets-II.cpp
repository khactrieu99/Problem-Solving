#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int n, res=0;

void solve() {
    int m=n*(n+1)/4;
    vector<vector<int>>trace(n+1, vector<int>(m+1,0));
        
    trace[0][0]=1;
    for(int i=1; i<=n; i++) trace[i][0]=1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(j>=i) {
                trace[i][j]=(trace[i-1][j]%MOD + trace[i-1][j-i]%MOD)%MOD;
            } else {
                trace[i][j]=trace[i-1][j];
            }    
        }
    }

    res=trace[n-1][m];
}

int main() {
    cin >> n;
    if((n*(n+1)/2)%2==0) {
        solve();
    }
    cout << res << endl;;
    return 0;
}
