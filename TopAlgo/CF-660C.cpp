#include <bits/stdc++.h>
using namespace std;

int n, k, l=0, r=0, ml=-1, mr=-1, curZero=0, ans=0;
vector<int> a;
int main() {
    cin >> n >> k;
    a.resize(n);
    for(auto &v: a) cin >> v;

    while(r<n) {
        while(r<n && (curZero<k || a[r]==1)) {
            if(a[r]==0) ++curZero;
            ++r;
        }
        
        if(r-l>ans) {
            mr=r; ml=l;
            ans=r-l;
        }

        while(l<=r && l<n && (curZero >=k)) {
            if(a[l]==0) --curZero;
            ++l;
        }
    }

    cout << mr - ml << endl;
    for(int i=0; i<a.size(); i++) {
        if(i>=ml && i<mr) cout << "1 ";
        else cout << a[i] << " ";
    }

    return 0;
}
