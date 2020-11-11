#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;

int n;
ll res=1;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        res = (res*2) % MOD;
    }
    cout << res << endl;
    return 0;
}