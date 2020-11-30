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
        f[i]=min(f[i],val);
        i+=(i&-i);
    }
}

int get(int i, int j) {
    int res=INT_MAX;
    while(i<=j) {
        if(i<=j-(j&-j)) {
            res=min(res,f[j]);
            j-=(j&-j);
        }
        else {
            res=min(res,x[--j]);
        }
    }
    return res;
}

int main() {
    cin >> n >> q;
    x.resize(n);
    f.resize(n+1, INT_MAX);

    for(auto &val: x) {
        cin >> val;
        update(bit++, val);
    }
    
    while(q--) {
        cin >> a >> b;
        cout << get(a,b) << endl;
    }

    return 0;
}	
