#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001
#define all(x) x.begin(),x.end()

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define REPL(i,a,b) for(int i=a; i<=b; i++)
#define RFOR(i,a,b) for(int i=b; i>a; i--)
#define RREPL(i,a,b) for(int i=b; i>=a; i--)

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int n, x;
ll mid, l, r, temp;
vi a;

bool check(ll m) {
    ll res = 0;
    FOR(i,0,n) {
        res += min(m/a[i],(ll)1e9);
    }
    return res>=x;  
}

int main() {
    // get input
    cin >> n >> x;
    a.resize(n);
    FOR(i,0,n) cin >> a[i];

    l=0; r=(ll)1e18;
    while(l<r) {
        mid=(l+r)/2;
        if(check(mid)) {
            r=mid;
        }
        else l=mid+1;
    }
    cout << l << endl;
    return 0;
}