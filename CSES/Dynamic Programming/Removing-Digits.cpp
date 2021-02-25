#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dp;

int main() {
    cin >> n;
    dp.resize(n+1, INT_MAX);
    dp[0]=0;

    for(int value=1; value<=n; value++) {
        int v=value;
        while(v>0) {
            int digit=v%10;
            dp[v]=min(dp[v],dp[v-digit]);
            v /= 10;
        }

        dp[v]++;
    }

    cout << dp[n] << endl;
    return 0;
}