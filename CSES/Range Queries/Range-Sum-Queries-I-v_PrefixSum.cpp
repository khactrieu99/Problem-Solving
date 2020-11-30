#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

vi x;
vll prefix;
int n, q, a, b;

int main() { 
    cin >> n >> q;
    x.resize(n);
    prefix.push_back(0);

    for(auto &val: x) {
        cin >> val;
        prefix.push_back(prefix.back() + val);
    }

    while(q--) {
        cin >> a >> b;
        cout << prefix[b] - prefix[a] + x[a-1] << endl;
    }

    return 0;
}
