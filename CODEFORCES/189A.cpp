#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
vector<int> dp;
int main() {
    cin >> n >> a >> b >> c;
    dp.resize(n+1, INT_MIN);
    
    dp[0]=0;
    for(int i=1; i<=n; i++) {
        if(i>=a) dp[i]=max(dp[i-a]+1,dp[i]);
        if(i>=b) dp[i]=max(dp[i-b]+1,dp[i]);
        if(i>=c) dp[i]=max(dp[i-c]+1,dp[i]);
    }
    cout << dp[n] << endl;
    return 0;
}
