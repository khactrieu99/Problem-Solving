#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, q, u, k, a, b, t;
vi x;
vll f;

void down(int id) {
    f[id*2] += f[id];
    f[id*2+1] += f[id];
    f[id] = 0;
}

void update(int id, int l, int r, int a, int b, int val) {
    if(l>b || r<a) return;
    if(a<=l && b>=r) {
        f[id] += val;
        return;
    }
    
    down(id);
    
    int mid=(l+r)/2;
    update(id*2,l, mid, a, b, val);
    update(id*2+1, mid+1, r, a, b, val);
}

void get(int id, int l, int r, int k) {
    if(k<l || k>r) return;
    if(l==r) {
        cout << f[id] + x[l-1] << endl;
        return;
    }

    down(id);

    int mid=(l+r)/2;
    get(id*2,l,mid,k);
    get(id*2+1,mid+1,r,k);
}

int main() {
    cin >> n >> q;
    x.resize(n);
    f.resize(4*n+1,0);
    
    for(auto &val: x) {
        cin >> val;
    }

    while(q--) {
        cin >> t;
        if(t==1) {
            cin >> a >> b >> u;
            update(1,1,n,a,b,u);
        }
        else {
            cin >> k;
            get(1,1,n,k);
        }
    }

    return 0;
}
