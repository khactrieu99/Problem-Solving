#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, q, t, a, b, u, k;
vi x, f;

void update(int id, int l, int r, int 

int main() {
    cin >> n >> q;
    x.resize(n);
    f.resize(4*n+1,0);
    for(auto &val: x) {
        cin >> x;
    }

    while(q--) {
        cin >> t;
        if(t==1) {
            cin >> a >> b >> u;
        }
        else if(t==2) {
            cin >> k;

        }
    }
    return 0;
}
