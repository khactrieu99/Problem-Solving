#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<int> w, v;
vector<vector<int>> dp;
int main() {
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        w.push_back(a);
        v.push_back(b);
    }
    dp = vector<vector<int>>(n+1, vector<int>(s+1, 0));
        
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=s; j++) {
            dp[i][j]=dp[i-1][j];
            if(j>=w[i-1] && dp[i-1][j-w[i-1]]+v[i-1] > dp[i-1][j]) {
                dp[i][j] = dp[i-1][j-w[i-1]] + v[i-1];
            }
        }
    }

    cout << dp[n][s] << endl;

    return 0;
}
