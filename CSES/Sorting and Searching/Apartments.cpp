#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 200001
typedef long long ll;
ll n, m, k, cnt=0, pos_a=0, pos_b=0;
ll a[MAXN], b[MAXN];
 
int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    sort(a, a+n, greater<ll>());
    sort(b, b+m, greater<ll>());
 
    while(pos_a<n&&pos_b<m) {
        if(abs(b[pos_b]-a[pos_a]) <= k) {
            pos_a++;
            pos_b++;
            cnt++;
        }
        else if(b[pos_b]>a[pos_a]) {
            pos_b++;
        }
        else if(a[pos_a]>b[pos_b]) {
            pos_a++;
        }
    }
 
    cout << cnt << endl;
    return 0;
}