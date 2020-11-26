#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 60001
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
 
int n, x;
ll res=0;
vi v;
vll f(MAXN*4,0);
 
void compress(vi &a) {
    set<int> s(a.begin(),a.end());
    vi b(s.begin(),s.end());
    for(auto &x: a) {
        x = lower_bound(b.begin(),b.end(),x) - b.begin() + 1;
    }
}
 
void update(int node, int l, int r, int val) {
    if(l>val||r<val) return;
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
    if(val>=r) return 0;
    if(val<l) {
        return f[node];
    }
    
    int mid=(l+r)/2;
    
    if(mid<=val) return get(node*2+1,mid+1,r,val);
    return get(node*2, l, mid, val) + get(node*2+1, mid+1, r, val);
}
 
int main() {
    cin >> n;
    v.resize(n);
 
    for(auto &val: v) {
        cin >> val;
    }
 
    compress(v);

    for(auto val: v) {
        update(1, 1, n, val);
        res += get(1, 1, n, val);
    }
 
    cout << res << endl;
    return 0;
}
