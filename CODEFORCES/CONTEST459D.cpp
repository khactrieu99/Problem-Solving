#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n;
ll res=0;
vi a, lcnt, rcnt, l, r, f;

void compress(vi &v) {
    set<int> s(v.begin(),v.end());
    vi b(s.begin(),s.end());
    for(auto &val: v) {
        val = lower_bound(b.begin(),b.end(),val) - b.begin() + 1;
    }
}

void update(int x) {
    while(x<=n) {
        f[x]++;
        x=x+(x&-x);
    }
}

int get(int x) {
    int res=0;
    while(x>0) {
        res+=f[x];
        x=x-(x&-x);
    }
    return res;
}

int main() {
    cin >> n;
    a.resize(n);
    lcnt.resize(n+1);
    rcnt.resize(n+1);
    l.resize(n+1);
    r.resize(n+1);
    f.resize(n+1,0);

    for(auto &val: a) {
        cin >> val;
    }
    
    compress(a);
    
    for(int i=0; i<n; i++) {
        l[i+1] = ++lcnt[a[i]];
    }
    for(int i=n-1; i>=0; i--) {
        r[i+1] = ++rcnt[a[i]];
    }

    for(int i=n; i>0; i--) {
        res+=get(l[i]-1);
        update(r[i]);
    }

    cout << res << endl;
    
    return 0;
}
