#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef long long ll;

int n, x, l, r, t;
vector< pair<int,int> > v;

int main() {
    cin >> n >> x;
    for(int i=0; i<n; i++) {
        cin >> t;
        v.push_back(make_pair(t, i+1));
    }

    sort(v.begin(), v.end());

    l=0; r=n-1;

    while(l<r) {
        if(v[l].first+v[r].first==x) {
            break;
        }
        else if(v[l].first+v[r].first>x) r--;
        else l++;
    }

    if(l<r) cout << v[l].second << " " << v[r].second << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}