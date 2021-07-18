#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int solve() {
    vector<int> seq(n, 1);
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(a[i]>a[j]) seq[i]=max(seq[i],seq[j]+1);
        }
    }
    return seq[n-1];
}

int main() {
    cin >> n;
    a.resize(n);
    for(auto &i: a) cin >> i;
    cout << solve() << endl;    
    return 0;
}
