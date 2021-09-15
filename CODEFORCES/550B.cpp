#include <bits/stdc++.h>
using namespace std;

int n, l, r, x, cnt=0;
vector<int> a;
int main() {
    cin >> n >> l >> r >> x;
    a.resize(n);
    for(auto &i: a) cin >> i;
    sort(a.begin(), a.end());
    
    for(int i=0; i<(1<<n); i++) {
        int minn=-1, maxx=-1, total=0;
        for(int j=0; j<n; j++) {
            if((i&(1<<j)) && minn==-1) minn=a[j];
            if((i&(1<<j))) {
                maxx=a[j];
                total+=a[j];
            }
        }
        if(total>=l && total<=r && maxx-minn>=x) cnt++;
    }

    cout << cnt << endl;
    return 0;
}
