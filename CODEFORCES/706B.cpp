#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> x;
int main() {
    cin >> n;
    x.resize(n);
    for(auto &v: x) cin >> v;
    
    sort(x.begin(), x.end());

    cin >> q;
    for(int i=0; i<q; i++) {
        int v; cin >> v;
        auto iteFound = upper_bound(x.begin(), x.end(), v);
        if(iteFound == x.end()) cout << n << endl;
        else cout << iteFound-x.begin() << endl;
    }
   
    return 0;
}
