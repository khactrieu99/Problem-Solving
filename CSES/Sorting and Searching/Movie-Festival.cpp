#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
int n, a, b, curr, ans=1;
vector< pair<int,int> > v;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(all(v));

    curr=v[0].first;
    for(int i=1; i<n; i++) {
        if(v[i].second>=curr) {
            ans++;
            curr=v[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}