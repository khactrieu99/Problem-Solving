#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n;
vector<vi> dp;

int main() {
    cin >> n;
    dp.resize(n+1);
    for(int i=0; i<=n; i++) {
        dp[i].resize(n+1);
    }
    return 0;
}
