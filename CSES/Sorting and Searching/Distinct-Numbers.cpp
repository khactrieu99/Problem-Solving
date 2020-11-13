#include <bits/stdc++.h>
using namespace std;

set<int> check;
int n, x; 

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        check.insert(x);
    }
    cout << check.size() << endl;
    return 0;
}