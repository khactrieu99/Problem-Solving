#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, q, a, b, bit=1;
vi x, f;

void update(int i, int val) {
    while(i<=n) {
        if(f[i]==-1)
            f[i]=val;
        else f[i]^=val;
        i+=(i&-i);
    }
}

void get(int i, int j) {
    ll res=-1;
    while(j>=i) {
        if(j-(j&-j)>=i) {
            if(res==-1)
                res=f[j];
            else res^=f[j];
            j-=(j&-j);
        }
        else {
            if(res==-1) res=x[j-1];
            else res^=x[j-1];
            j--;
        }
    }

    cout << res << endl;
}

int main() {
    cin >> n >> q;
    x.resize(n);
    f.resize(n+1, -1);
    for(auto &val: x) {
        cin >> val;
        update(bit++,val);
    }

    while(q--) {
        cin >> a >> b;
        get(a,b);
    }
    return 0;
}
