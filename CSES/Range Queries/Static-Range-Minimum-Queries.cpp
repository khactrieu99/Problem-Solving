#include <bits/stdc++.h>
using namespace std;

int n, q, l, r;
vector<int> a;
vector<int> LOG;
vector<vector<int>> query;

int main() {
    cin >> n >> q;
    a.resize(n);
    LOG.resize(n+1,0);

    for(int i=1; i<=n; i++) {
        LOG[i]=LOG[i/2]+1;
    }
    query.resize(n+1, vector<int>(LOG[n]+1));

    for(auto &v: a) cin >> v;
    for(int i=0; i<n; i++) query[i][0]=a[i];

    for(int j=1; j<=LOG[n]; j++) {
        for(int i=1; i+(1<<j)<=n; i++) {
            query[i][j]=min(query[i][j-1], query[i+(1<<(j-1))][j-1]);
        }
    }
    while(q--) {
        cin >> l >> r;
        cout << min(query[l][LOG[r-l+1]], query[r-(1<<LOG[r-l+1])][LOG[r-l+1]]) << endl;
    } 
    return 0;
}
