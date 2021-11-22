#include <bits/stdc++.h>
using namespace std;

#define MAXM 55
#define MAXN 255

int n, m;
int a[MAXM];
int dp[MAXM][MAXN];

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) cin >> a[i];
    for(int i=0; i<n; i++) dp[0][i]=0;
    for(int i=0; i<m; i++) dp[i][0]=0;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<m; j++) {
            if(i>=a[j]) dp[j][i]=dp[j][i-a[j]]+dp[j-1][i];
        }
    }
    cout << dp[m-1][n] << endl;
    return 0;
}
