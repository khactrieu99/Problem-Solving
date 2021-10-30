#include <bits/stdc++.h>
using namespace std;

int t, n, k;
vector<int> a;
int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        a.resize(k);
        for(auto &v: a) cin >> v;

        sort(a.begin(), a.end());
        int s=0, i=a.size()-1;
        while(s+(n-a[i])<n && i>=0) {
            s+=n-a[i];
            i--;
        }
        cout << a.size()-1-i << endl;
    }
    return 0;
}
