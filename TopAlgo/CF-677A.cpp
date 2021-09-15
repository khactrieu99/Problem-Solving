#include <bits/stdc++.h>
using namespace std;

int n, h, ans=0;
int main() {
    cin >> n >> h;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        ans+=((x>h)?2:1);
    }
    cout << ans << endl;
    return 0;
}
