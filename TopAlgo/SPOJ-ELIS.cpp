#include <bits/stdc++.h>
using namespace std;

int n, ans=0;
int a[11], dp[11];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        dp[i]=1;
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(a[j]<a[i]) {
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
    }  
    for(int i=0; i<n; i++) {
        ans=max(ans,dp[i]);
    }
    cout << ans << endl;
    return 0;
}
