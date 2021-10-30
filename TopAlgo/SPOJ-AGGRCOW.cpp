#include <bits/stdc++.h>
using namespace std;

int t, n, c;
vector<int> x;
int main() {
    cin >> t;
    while(t--) {
        cin >> n >> c;
        x.resize(n);
        for(auto &v: x) cin >> v;
        sort(x.begin(),x.end());
        int l=1, r=1000000000, ans=1;
        int i, j, b;
        while(l<=r) {
            int mid=l+(r-l)/2;
            for(b=0, i=1, j=1; i<n && j<c; i++) {
                if(x[i]-mid>=x[b]) {
                    b=i; j++;
                }
            }  
            if(j==c) ans=mid;
            if(j<c) r=mid-1;
            else l=mid+1;
        }
        cout << ans << endl;
    }
    return 0;
}
