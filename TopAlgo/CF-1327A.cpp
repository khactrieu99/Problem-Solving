#include<bits/stdc++.h>
using namespace std;

long long t, n, k;
int main() {
    cin >> t;
    
    while(t--) {
        cin >> n >> k;
        if((n-k)%2!=0) cout << "NO" << endl;
        else {
            long long h=(k*(k-1))/2;
            long long v=(n-k)/2;
            if(h<=v) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}
