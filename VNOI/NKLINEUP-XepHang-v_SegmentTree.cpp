#include <bits/stdc++.h>
using namespace std;

#define MAXN 50001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, q, x, y;
vector<pii> f(MAXN*4,{0,INT_MAX}); // { first: MAX, second: MIN }
vi v;

void update(int node, int l, int r, int i, int val) {
    if(i<l || i>r) return;
    if(l==r) {
        f[node] = make_pair(val,val);
        return;
    }
    
    int mid=(l+r)/2;
    
    update(node*2, l, mid, i, val);
    update(node*2+1, mid+1, r, i, val);

    f[node].first = max(f[node*2].first,f[node*2+1].first);
    f[node].second = min(f[node*2].second, f[node*2+1].second);
}

pii get(int node, int l, int r, int p, int q) {
    if(p>r || q<l) {
        return make_pair(INT_MIN, INT_MAX);
    }
    
    if(p<=l && q>=r) {
        return f[node];
    }

    int mid=(l+r)/2;
    
    pii left = get(node*2,l,mid,p,q);
    pii right = get(node*2+1,mid+1,r,p,q);

    int maxx=max(left.first,right.first);
    int minn=min(left.second,right.second);

    return make_pair(maxx,minn);
}

int main() {
    cin >> n >> q;
    v.resize(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
        update(1, 1, n, i+1, v[i]);
    }

    while(q--) {
        cin >> x >> y;
        pii res = get(1,1,n,x,y);
        cout << res.first - res.second << endl;
    }

    return 0;
}
