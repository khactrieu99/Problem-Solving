#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 200001
 
int n, x, cnt=0, l, r;
int p[MAXN];
 
int main() {
    cin >> n >> x;
    for(int i=0; i<n; i++) cin >> p[i];
 
    l=0; r=n-1;
 
    sort(p, p+n);
    
    while(l<r) {
        if(p[l]+p[r]<=x) {
            l++; r--;
            cnt++;
        }
        else {
            r--; cnt++;
        }
        if(l==r) cnt++;
    }
 
    cout << cnt << endl;
 
    return 0;
}