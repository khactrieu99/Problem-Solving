#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef long long ll;

int n;
ll ans=0;
int p[MAXN];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> p[i];
    sort(p, p+n);
    for(int i=0; i<n; i++) ans += abs(p[i]-p[n/2]);
    cout << ans << endl;
    return 0;
}