#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, m, r;
vi h, f;

void update(int id, int l, int r, int i, int val) {
    if(i<l || i>r) return;
    if(l==r) {
        f[id]=val;
        return;
    }

    int mid=(l+r)/2;
    update(id*2,l,mid,i,val);
    update(id*2+1,mid+1,r,i,val);

    f[id]=max(f[id*2],f[id*2+1]);
}

int get(int id, int l, int r, int val) { 
    if(l==r) {
        update(1,1,n,l,h[l-1]-=val);
        return l;
    }

    int mid=(l+r)/2;
    if(f[id*2]>=val) return get(id*2,l,mid,val);
    if(f[id*2+1]>=val) return get(id*2+1,mid+1,r,val);

    return 0;
}

int main() {
    cin >> n >> m;
    h.resize(n);
    f.resize(n*4+1);
    for(int i=0; i<n; i++) {
        cin >> h[i];
        update(1,1,n,i+1,h[i]);
    }
    
    while(m--) {
        cin >> r;
        cout << ( f[1] < r ? 0 : get(1,1,n,r) ) << " "; 
    }
    cout << endl;
    return 0;
}
