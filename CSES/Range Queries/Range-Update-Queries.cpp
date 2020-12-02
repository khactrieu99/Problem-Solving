#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

typedef struct {
    int val, lazy;
} node;

int n, q, u, k, a, b, t;
vi x;
vector<node> f;

void update() {

}

int get() {

}

int main() {
    cin >> n >> q;
    x.resize(n);
    f.resize(4*n);
    
    for(auto &val: x) {
        cin >> val;
    }

    while(q--) {
        cin >> t;
        if(t==1) {
            cin >> a >> b >> u;
        }
        else {
            cin >> k;
            cout << get(k) << endl;
        }
    }

    return 0;
}
