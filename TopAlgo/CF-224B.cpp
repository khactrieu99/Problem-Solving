#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;
unordered_map<int, int> m;
int main() {
    cin >> n >> k;
    a.resize(n);
    for(auto &v: a) cin >> v;
    
    if(k==1) {
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    int l=0, r=0;
    while(m.size()<k && r<n) {    
        ++m[a[r++]];
    }
    if(m.size()==k) {
        while(m[a[l]]>1) {
            --m[a[l++]];
        }
        cout << l+1 << " " << r << endl;
        return 0;
    }
    cout << -1 << " " << -1 << endl;

    return 0;
}
