#include <bits/stdc++.h>
using namespace std;

unsigned long long t, x, y;

int main() {
    cin >> t;
    while(t--) {
        cin >> y >> x;
        unsigned long long res=1;
        unsigned long long maxx = ( x > y ? x : y );
        if(maxx%2==1)
            res = (maxx-1)*(maxx-1) + x + (maxx - y);
        else 
            res = (maxx-1)*(maxx-1) + y + (maxx - x);
        cout << res << endl;
    }
    return 0;
}