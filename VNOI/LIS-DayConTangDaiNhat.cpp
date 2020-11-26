#include <bits/stdc++.h>
using namespace std;

#define MAXN 30001

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pii;

ll n;
vl a, f;

void compress(vl &a) {
    set<ll> s(a.begin(),a.end());
    vl b(s.begin(),s.end());
    for(auto &x: a) {
        x = lower_bound(b.begin(),b.end(),x) - b.begin() + 1;
    }   
}

void update(ll x, ll val) {
    while(x<=n) {
        f[x]=max(f[x],val);    
        x=x+(x&-x);
    }   
}

ll get(ll x) {
    ll res=0;
    while(x>0) {
        res=max(res,f[x]);
        x=x-(x&-x);
    }

    return res;
}

int main() {
    cin >> n;
    a.resize(n);
    f.resize(n+1,0);

    for(ll i=0; i<n; i++) cin >> a[i];
      
    compress(a);

    for(auto x: a) {
        update(x, get(x-1)+1);
    }

    cout << get(n) << endl;
    
    return 0;
}
