#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001
#define all(x) x.begin(),x.end()

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int n, x, y;
ll s=0, ans=0;
vector<pii> a;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        a.push_back({x,y});
    }
    sort(all(a));
    for(auto item: a) {
        s+=item.first;
        ans+=(item.second-s);
    }
    cout << ans << endl;
    return 0;
}