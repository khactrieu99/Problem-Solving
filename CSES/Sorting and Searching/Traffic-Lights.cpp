#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef pair<int,int> pii;

int x, n, t, res=0;

set<int> s;
set<int>::iterator it;
multiset<int> w;

int main() {
    cin >> x >> n;
    s.insert(x);
    s.insert(0);

    w.insert(x);

    while(n--) {
        cin >> t;

        it=s.lower_bound(t);
        int r=*it, l=*prev(it);

        s.insert(t);
        w.erase(w.find(r-l));
        w.insert(r-t);
        w.insert(t-l);

        cout << *prev(w.end()) << " ";
    }

    cout << endl;

    return 0;
}