#include <bits/stdc++.h>
using namespace std;

int n, t, i;
vector<int> a;
int main() {
    cin >> n >> t;
    a.resize(n+1);
    for(int i=1; i<n; i++) cin >> a[i];
    
    i=1;
    while(i<=t && i<=n) {
        if(i==t) {
            cout << "YES" << endl;
            return 0;
        }
        i+=a[i];
    }
    cout << "NO" << endl;

    return 0;
}
