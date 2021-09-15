#include <bits/stdc++.h>
using namespace std;

int n, m, k, cnt=0;    
vector<int> p;
int main() {
    cin >> n >> m >> k;
    p.resize(m+1);
    for(auto &i: p) cin >> i;
    for(int i=0; i<m; i++) cnt+=(__builtin_popcount(p[m]^p[i])<=k)? 1:0;
    cout << cnt << endl;
    return 0;
}
