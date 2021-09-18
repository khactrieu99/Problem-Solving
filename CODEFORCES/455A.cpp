#include<bits/stdc++.h>
using namespace std;

int n;
long long dp[100001];
long long cnt[100001]={0};

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    dp[0]=0; dp[1]=cnt[1];
    for(long long i=2; i<=100001; i++) {
        dp[i]=max(dp[i-1], dp[i-2]+cnt[i]*i);
    }

    cout << dp[100000] << endl;
    return 0;
}
