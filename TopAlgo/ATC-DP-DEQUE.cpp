#include <bits/stdc++.h>
using namespace std;

#define MAXN 3001

int n;
int a[MAXN];
long long dp[MAXN][MAXN];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        dp[i][i]=a[i];
    }
    for(int j=0; j<n; j++) {
        for(int i=j; i>=0; i--) {
            if(i!=j) {
                dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
    
    return 0;
}
