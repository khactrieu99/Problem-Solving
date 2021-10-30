#include<bits/stdc++.h>
using namespace std;

int n, q, val, found, l, r, mid, c=1;
vector<int> a;
int main() {
    while(true) {
        cin >> n >> q;
        if(n==0 && q==0) return 0;
        a.resize(n);
        for(auto &v: a) cin >> v;
        sort(a.begin(),a.end());
        found=-1;
        cout << "CASE# " << c++ << endl;
        while(q--) {
            cin >> val;
            l=0; r=n-1;
            while(l<=r) {
                mid=l+(r-l)/2;
                if(a[mid]>=val) {
                    if(a[mid]==val) found=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }    
            if(found==-1) cout << val << " not found" << endl;
            else cout << val << " found at " << found + 1 << endl;  
        } 
    }    
    return 0;
}
