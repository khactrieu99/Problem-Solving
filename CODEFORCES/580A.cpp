#include <bits/stdc++.h>
using namespace std;

int n, m=0;
vector<int> dp, a;
int main() {
    cin >> n;
    dp.resize(n+1);
    a.resize(n+1);

    dp[0]=0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(i>0&&a[i]>=a[i-1]) dp[i]=dp[i-1]+1;
        else dp[i]=1;
        
        m=max(m,dp[i]);
    }

    cout << m << endl;
    return 0;
}
