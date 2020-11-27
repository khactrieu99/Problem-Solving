#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n;
ll res=0;
vi a, lcnt, rcnt, l, r;
vll f;

void compress(vi &a) {
    set<int> s(a.begin(),a.end());
    vi b(s.begin(),s.end());
    for(auto &x: a) {
        x = lower_bound(b.begin(),b.end(),x) - b.begin() + 1;
    }
}
 
void update(int node, int l, int r, int val) {
    if(r<=val) return;
    if(l==r) {
        f[node]++;
        return;
    }
   
    int mid=(l+r)/2;
 
    update(node*2, l, mid, val);
    update(node*2+1, mid+1, r, val);
 
    f[node]++;
}
 
ll get(int node, int l, int r, int val) {
    if(val<=l) return 0;
    if(val>r) {
        return f[node];
    }
    
    int mid=(l+r)/2;
    
    // if(mid>=val) return get(node*2,l,mid,val);
    return get(node*2, l, mid, val) + get(node*2+1, mid+1, r, val);
}

int main() {
    cin >> n;
    a.resize(n);
    l.resize(n+1);
    r.resize(n+1);
    lcnt.resize(n+1);
    rcnt.resize(n+1);
    f.resize(4*n+4,0);

    for(auto &val: a) cin >> val;
    compress(a);

    for(int i=0; i<n; i++) {
        l[i+1] = ++lcnt[a[i]];
    }

    for(int i=n-1; i>=0; i--) {
        r[i+1] = ++rcnt[a[i]];
    }
    
    for(int i=n-1; i>=0; i--) {
        res += get(1,1,n,l[i+1]);
        update(1,1,n,r[i+1]);
    }

    cout << res << endl;

    return 0;
}
