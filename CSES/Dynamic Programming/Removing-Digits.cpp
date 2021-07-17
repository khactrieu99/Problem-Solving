#include<bits/stdc++.h>
using namespace std;

#define MAX 1000001

int n;

int solve(int inp) {
    vector<int> dp(inp+1, MAX);
    
    dp[0]=0;
    for(int i=1; i<=inp; i++) {
        int t=i;
        while(t) {
            int digit=t%10;
            dp[i]=min(dp[i-digit]+1, dp[i]);
            t/=10;
        }
    }

    return dp[inp];
}

int main() {
    cin >> n;
    cout << solve(n) << endl;
	return 0;
}
