#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, x;
int k[MAXN];
multiset<int> s;
multiset<int>::iterator it;

int main() {
    cin >> n;
    while(n--) {
        cin >> x;
        it = s.upper_bound(x);
        if(it==s.end()) {
            s.insert(x);
        }
        else {
            s.erase(it);
            s.insert(x);
        }
    }
    cout << s.size() << endl;
    return 0;
}