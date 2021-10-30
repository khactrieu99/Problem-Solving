#include<bits/stdc++.h>
using namespace std;

int t, n, k, maxDiff=INT_MIN, ans=1, c=1;
vector<int> a;

void solve() {
    int l=1, r=maxDiff;
    while(l<=r) {
        int mid=l+(r-l)/2;
        int s=0;
        for(int i=1; i<n; i++) {
            int diff=a[i]-a[i-1];
            int cnt=(diff-1)/mid;
            s+=cnt;
        }
        if(s<=k) {
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        a.resize(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
            if(i>0) maxDiff=max(maxDiff,a[i]-a[i-1]);
        }
        if(maxDiff==1) {
            cout << 1;
            continue;
        }   
        solve();
        cout << "Case #" << c++ << ": " << ans << endl;
    }
    return 0;
}
