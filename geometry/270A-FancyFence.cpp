#include <bits/stdc++.h>
using namespace std;

int t, angle;
int main() {
    cin >> t;
    while(t--) {
        cin >> angle;
        cout << ((360%(180-angle)==0)? "YES":"NO") << endl;
    }
    return 0;
}