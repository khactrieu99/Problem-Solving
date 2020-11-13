#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, m, x;
int t[MAXN];

struct comparator {
    bool operator() (const int &a, const int &b) const {
        return a > b;
    }
};

multiset<int, comparator> s;
multiset<int>::iterator it;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> x;
        s.insert(x);
    }

    for(int i=0; i<m; i++) {
        cin >> x;
        it = s.lower_bound(x);
        if(it!=s.end()) {
            cout << *it << endl;
            s.erase(it);
        }
        else cout << -1 << endl;    
    }

    return 0;
}