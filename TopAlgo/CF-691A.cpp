#include <bits/stdc++.h>
using namespace std;

int n, cnt=0;
int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        if(x==1) cnt++; 
    }
    cout << (((n==1&&cnt==1)||(n!=1&&cnt==n-1))?"YES":"NO") << endl;
    return 0;
}
