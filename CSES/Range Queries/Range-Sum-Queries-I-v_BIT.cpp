#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, q, a, b, bit=1;
vi x;
vll f;

void update(int i, int val) {
    while(i<=n) {
        f[i]+=val;
        i+=(i&-i);
    }
}

ll get(int i, int j) {
    ll res=0;
    while(j>=i) {
        if(j-(j&-j)>=i) {
            res+=f[j];
            j-=(j&-j);
        }
        else {
            res+=x[j-1];
            j--;
        }
    }

    return res;
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
        cin >> a >> b;
        cout << get(a,b) << endl;
    }

    return 0;
}
