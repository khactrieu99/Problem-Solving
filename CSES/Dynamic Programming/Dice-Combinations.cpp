#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001

const int MOD = 1000000007;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, ans;
vector<int> subtract(7,0);

int main() {
    cin >> n;

    subtract[0]=1;
    for(int i=1; i<=6; i++) {
        for(int j=1; j<=6; j++) {
            if(i>=j) subtract[i]+=subtract[i-j] % MOD;
        }
    }

    if(n<=6) {
        cout << subtract[n] << endl;
        return 0;
    }

    for(int i=7; i<=n; i++) {
        ans=0;
        for(int j=1; j<=6; j++) {
            ans += subtract[j] % MOD;
            ans %= MOD;
        }

        for(int j=1; j<6; j++) {
            subtract[j]=subtract[j+1]%MOD;
        }

        subtract[6]=ans;
    }

    cout << ans << endl;

    return 0;
}
