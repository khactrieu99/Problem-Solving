#include<bits/stdc++.h>
using namespace std;

int n, m, cnt=0;
vector<int> a, b;
int main() {
    cin >> n;
    a.resize(n);
    for(auto &v: a) cin >> v;
    sort(a.begin(), a.end());

    cin >> m;
    b.resize(m);
    for(auto &v: b) cin >> v;
    sort(b.begin(), b.end());

    int i=0, j=0;
    while(i<n && j<m) {
        if(abs(a[i]-b[j])<=1) {
            cnt++; i++; j++;
        } else if(a[i]>b[j]) j++;
        else i++;
    }

    cout << cnt << endl;

    return 0;
}
