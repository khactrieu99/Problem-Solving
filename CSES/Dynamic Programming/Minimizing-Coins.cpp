#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int n, x, ans=0;
int c[101];
vector<int> dp;

int main() {
    cin >> n >> x;

    dp.resize(x+1, MAX);

    for(int i=0; i<n; i++) cin >> c[i];

    sort(c, c+n);
    dp[0]=0;

    for(int i=1; i<=x; i++) {
        for(int j=0; j<n; j++) {
            if(i>=c[j]) {
                dp[i]=min(dp[i], dp[i-c[j]]+1);
            }
        }
    }

    cout << ((dp[x]==MAX)?-1:dp[x]) << endl;
    return 0;
}