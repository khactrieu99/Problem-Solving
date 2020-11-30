#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, q, a, b, t, k, u, add, bit=1;
vi x;
vll f;

void update(int i, int val) {
    while(i<=n) {
        f[i]+=val;
        i+=(i&-i);
    }   
}

void get(int i, int j) {
    ll res=0;
    while(j>=i) {
        if(j-(j&-j)>=i) {
            res+=f[j];
            j-=(j&-j);
        }
        else res+=x[--j];
    }
    cout << res << endl;
}

int main() {
    cin >> n >> q;
    x.resize(n);
    f.resize(n+1, 0);    

    for(auto &val: x) {
        cin >> val;
        update(bit++, val);
    }
    
    while(q--) {
        cin >> t;
        if(t==1) {
            cin >> k >> u;
            update(k,u-x[k-1]);
            x[k-1]=u;
        }   
        else if(t==2) {
            cin >> a >> b;
            get(a,b);
        }
    }
    return 0;
}
