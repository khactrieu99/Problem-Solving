#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a, b;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }    
    cin >> m;
    for(int i=0; i<m; i++) {
        int x; cin >> x;
        b.push_back(x);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i=0, j=0, res=0;
    while(i<n && j<m) {
        if(abs(a[i]-b[j])<=1) {
            res++;
            i++; j++;
        } else if(a[i]>b[j]) j++;
        else i++;
    }
    cout << res << endl;
    return 0;
}
