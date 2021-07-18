#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int t, n;

int solve() {
    vector<vector<int>> v(n+1, vector<int>(3, 1));
    
    return v[n][2];
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cout << solve() << endl;
    }   
    return 0;
}
