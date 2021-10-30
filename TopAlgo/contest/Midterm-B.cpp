#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    for(int i=1; i<n; i++) {
        if(i%2==0 && (n-i)%2==0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
