#include <bits/stdc++.h>
using namespace std;

int t, n, m, cnt=0;
vector<int> a;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        a.resize(n);
        cnt=0;
        for(auto &v: a) cin >> v;
        sort(a.begin(),a.end());
        
        for(int i=0; i<n; i++) {
            int val = m-a[i];
            int l=i+1, r=n-1;
            while(l<=r) {
                int mid=l+(r-l)/2;
                if(a[mid]==val) {
                    cnt++;
                    break;
                } 
                if(a[mid]>val) r=mid-1;
                else l=mid+1;
            }
        }
        
        cout << cnt << endl;
    }    
    return 0;
}
