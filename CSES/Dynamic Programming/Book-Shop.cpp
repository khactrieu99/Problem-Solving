#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for(auto &v: h) cin >> v;  
    for(auto &v: s) cin >> v; 

    for(int i=1; i<=n; i++) {
        for(int v=1; v<=x; v++) {
            if(h[i-1]>v) dp[i][v]=dp[i-1][v];
            else dp[i][v]=max(dp[i-1][v],dp[i-1][v-h[i-1]]+s[i-1]);
        }
    }

    cout << dp[n][x] << endl;
    return 0;
}