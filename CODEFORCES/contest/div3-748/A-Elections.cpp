#include <bits/stdc++.h>
using namespace std;

int t, a, b, c;

int solve(int val, int maxx) {
    if(val==maxx) return 0;
    else return maxx-val+1;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        int maxx=max(a,max(b,c));
        if((a==maxx&&a==b) || (b==maxx&&b==c) || (c==maxx&&c==a)) {
            maxx++;
            cout << maxx-a << " " << maxx-b << " " <<  maxx-c << endl;
            continue;
        }
        cout << solve(a,maxx) << " " << solve(b,maxx) << " " << solve(c,maxx) << endl; 
    }
    return 0;
}   
