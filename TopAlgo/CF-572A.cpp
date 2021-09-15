#include <bits/stdc++.h>
using namespace std;

int na, nb, k, m, xa, xb;
int main() {
    cin >> na >> nb >> k >> m;
    for(int i=0 ; i<na; i++) {
        int x; cin >> x;
        if(i == k-1) xa=x;
    }
    for(int i=0; i<nb; i++) {
        int x; cin >> x;
        if(i == nb-m) xb=x;
    }

    cout << ((xa<xb)? "YES":"NO") << endl;
    
    return 0;
}
