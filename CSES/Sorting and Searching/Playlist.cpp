#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef pair<int,int> pii;

struct comparator {
    bool operator() (const pii& a, const pii& b) const {
        return a.first < b.first;
    }
};

int n, x, res=1;
int f[MAXN];
set<pii,comparator> playlist;
set<pii,comparator> ::iterator it;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        pii p = make_pair(x, i);
        if(playlist.empty()) {
            f[i]=1;
            playlist.insert(p);
        }
        else {
            it = playlist.lower_bound(p);
            if(it!=playlist.end()&&it->first==x) {
                f[i] = min(i-it->second, f[i-1]+1);
                playlist.erase(it);
            }
            else {
                f[i] = f[i-1]+1;
            }
            playlist.insert(p);
            res=max(res,f[i]);
        }
    }
    cout << res << endl;
    return 0;
}