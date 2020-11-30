#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, q, t, k, u, a, b, bit=1;
vi x, f;

void update(int i, int val) {
    while(i<=n) {
        f[i]=min(f[i],val);
        i+=(i&-i);
    }
}

void get(int i, int j) {
    int res=INT_MAX;
    while(j>=i) {
        if(j-(j&-j)>=i) {
            res=min(res,f[j]);
            j-=(j&-j);
        }
        else res=min(res,x[--j]);
    }
    cout << res << endl;
}

int main () {
    cin >> n >> q;
    x.resize(n);
    f.resize(n+1, INT_MAX);
    for(auto &val: x) {
        cin >> val;
        update(bit++, val);
    }
    
    while(q--) {
        cin >> t;
        if(t==1) {
            cin >> k >> u;
            update(k,u);
            x[k-1]=u;
        }
        else if(t==2) {
            cin >> a >> b;
            get(a,b);
        }
    }

    return 0;
}
