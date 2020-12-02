#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, q, b, d, a, c;
vector<vi> dp;
char ch;

int main () {
    cin >> n >> q;
    dp.resize(n+1);
    for(int i=0; i<=n; i++) {
        dp[i].resize(n+1,0);
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> ch;
            dp[i][j]=dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if(ch=='*') dp[i][j]++;
        }
    }

    while(q--) {
        cin >> a >> b >> c >> d;
        cout << dp[c][d] - dp[c][b-1] - dp[a-1][d] + dp[a-1][b-1] << endl;     
    }
    return 0;
}
