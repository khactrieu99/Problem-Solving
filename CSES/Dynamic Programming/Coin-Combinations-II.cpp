#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int n, x;
int c[102];
vector<vector<int>> dp;

int main() {
    cin >> n >> x;

    dp.resize(n+1);
    for(int i=0; i<=n; i++) dp[i].resize(x+1, 0);
    dp[0][0]=1;

    for(int i=0; i<n; i++) cin >> c[i];
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=x; j++) {
            dp[i][j] = dp[i-1][j];
            if(j>=c[i-1]) (dp[i][j] += dp[i][j-c[i-1]]) %= MOD;
        }
    }

    cout << dp[n][x] << endl;
    return 0;
}