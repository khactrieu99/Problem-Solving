#include<bits/stdc++.h>
using namespace std;

int n, t, ans=0;
vector<int> prefix;
int main() {
    cin >> n >> t;
    prefix.resize(n+1);
    
    prefix[0]=0;
    for(int i=1; i<=n; i++) {
        int x; cin >> x;
        prefix[i]=prefix[i-1]+x;
    }
    
    // binary search O(nlog(n))
    //for(int i=1; i<=n; i++) {
    //    auto it = lower_bound(prefix.begin(), prefix.end(), prefix[i]-t);
    //    if(it!=prefix.end()) {
    //        int found = (it-prefix.begin());
    //        ans = max(ans, i-found);
    //    }
    //}
    
    // two pointers O(n)
    int i=0, j=1;
    while(j<=n) {
        if(prefix[j]-prefix[i] <= t) {
            ans=max(ans, j-i);
            ++j;
        } else {
            i++;
        }
    }
    
    cout << ans << endl;
    return 0;
}
