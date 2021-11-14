#include <bits/stdc++.h>
using namespace std;

#define MAXN 405

int n;
int a[MAXN];
long long cost[MAXN][MAXN], dp[MAXN][MAXN];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            dp[j][i]=LLONG_MAX;
            cost[j][i]=0;
        }
    }

    for(int i=1; i<=n; i++) {
        dp[i][1]=a[i-1];
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n-i+1; j++) {
            for(int k=1; k<i; k++) {
                dp[j][i]=dp[j][k]+dp[j+k][i-k];
                if(cost[j][i]==0) cost[j][i]=LLONG_MAX;
                cost[j][i]=min(cost[j][i],cost[j][k]+cost[j+k][i-k]+dp[j][i]);
            }
        }
    }
    
    cout << cost[1][n] << endl;
    return 0;
}
