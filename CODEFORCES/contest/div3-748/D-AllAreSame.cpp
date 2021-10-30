#include<bits/stdc++.h>
using namespace std;

int t, n, m=INT_MAX;
vector<int> a;

int gcd(int a, int b) {
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    if (a == b)
        return a;
  
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        a.resize(n);
        for(int i=0; i<n; i++) {
            int x; cin >> x;
            m=min(m,x);
            a[i] = x;
        }
        if(m<0) {
            for(int i=0; i<n; i++) a[i]-=m;
            m=0;
        }
        int cur=-1;
        for(int i=0; i<n; i++) {
            if(a[i]==m) continue;
            if(cur==-1) cur=a[i]-m;
            else cur=gcd(cur,a[i]-m);
        }
        cout << cur << endl;
    }    
    return 0;
}
