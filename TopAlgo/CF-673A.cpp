#include <bits/stdc++.h>
using namespace std;

int n, ans=0, nxt=15, last=0;
int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        if(x<=nxt) {
            ans+=x-last;
            nxt=x+15;
            last=x;
        }
    }

    if(nxt<90) ans+=15;
    else ans+=90-last;

    cout << ans << endl;
    return 0;
}
