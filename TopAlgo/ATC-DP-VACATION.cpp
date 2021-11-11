#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n;
int a[MAXN][3], dp[MAXN][3];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        dp[i][0]=0; dp[i][1]=0; dp[i][2]=0;
        if(i==0) {
            dp[i][0]=a[i][0];
            dp[i][1]=a[i][1];
            dp[i][2]=a[i][2];
        }
    }    
    for(int i=1; i<n; i++) {
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i][0];
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+a[i][1];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+a[i][2];
    }

    cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])) << endl;
    
    return 0;
}
