#include <bits/stdc++.h>
using namespace std;

unsigned int t, n, rs;
vector<int> a;
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        a.resize(n);
        rs=~0;
        for(auto &i: a) {
            cin >> i;
            rs&=i;
        }
        cout << rs << endl;
    }
    return 0;
}
