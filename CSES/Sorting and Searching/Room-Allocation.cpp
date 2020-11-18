#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vp;

int n, x, y, cnt=0;

vector< pair<pii,int> > a;
multimap<int,int,greater<int> > m;
multimap<int,int,greater<int> >::iterator it;

int main() {
    cin >> n;
    vi res(n);

    for(int i=0; i<n; i++) {
        cin >> x >> y;
        a.push_back(pair<pii,int>({x, y}, i));
    } 

    sort(all(a));

    for(auto item: a) {
        it=m.upper_bound(item.first.first);
        if(it!=m.end()) {
            m.insert({item.first.second, it->second});
            res[item.second]=it->second;
            m.erase(it);
        }
        else {
            cnt++;
            m.insert({item.first.second, cnt});
            res[item.second]=cnt;
        }
    }

    cout << cnt << endl;
    for(auto v: res) cout << v << " ";
    cout << endl;

    return 0;
}