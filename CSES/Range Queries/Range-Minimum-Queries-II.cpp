#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, q, t, k, u, a, b;
vi x, f;

void update(int id, int l, int r, int i, int val) {
    if(i<l || i>r) return;
    if(l==r) {
        f[id]=val;
        return;
    }

    int mid=(l+r)/2;
    update(id*2,l,mid,i,val);
    update(id*2+1,mid+1,r,i,val);

    f[id]=min(f[id*2],f[id*2+1]);
}

int get(int id, int l, int r, int u, int v) {
    if(u>r || v<l) return INT_MAX;
    if(u<=l && v>=r) return f[id];

    int mid=(l+r)/2;
    return min(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}

int main() {
    cin >> n >> q;
    x.resize(n);
    f.resize(n*4+1,INT_MAX);

    for(int i=0; i<n; ++i) {
        cin >> x[i];
        update(1,1,n,i+1,x[i]);
    }

    while(q--) {
        cin >> t;
        if(t==1) {
            cin >> k >> u;
            update(1,1,n,k,u);
        }
        else if(t==2) {
            cin >> a >> b;
            cout << get(1,1,n,a,b) << endl;
        }
    }   
    return 0;
}
