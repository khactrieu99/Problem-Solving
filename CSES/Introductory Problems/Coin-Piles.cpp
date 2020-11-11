#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(a>2*b||b>2*a) cout << "NO" << endl;
        else {
            if((2*a-b)%3==0&&(2*b-a)%3==0) cout << "YES" << endl;
            else cout << "NO" << endl;  
        }
    }
    return 0;
}