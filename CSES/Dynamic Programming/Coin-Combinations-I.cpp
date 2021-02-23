#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int n, x;
int c[101];

vector<int> dp;

int main() {
    cin >> n >> x;
    dp.resize(x+1, 0);
    dp[0]=1;

    for(int i=0; i<n; i++) cin >> c[i];
    for(int i=1; i<=x; i++) {
        for(int j=0; j<n; j++) {
            if(i>=c[j]) (dp[i] += dp[i-c[j]]) %= MOD;
        }
    }

    cout << dp[x] << endl;
    return 0;
}