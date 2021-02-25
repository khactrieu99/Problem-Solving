#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
int n;
vector<int> dp;

int main() {
    cin >> n;
    dp.resize(n+1, MAX);
    dp[0]=0;

    for(int value=1; value<=n; value++) {
        int v=value;
        while(v>0) {
            int digit=v%10;
            dp[value]=min(dp[value],dp[value-digit]+1);
            v/=10;
        }
    }

    cout << dp[n] << endl;
    return 0;
}