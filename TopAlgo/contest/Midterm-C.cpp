#include <bits/stdc++.h>
using namespace std;

int n, maxx=0, cur=0, a, b;
int main() {
    cin >> n;
    for(int i=0; i<n ;i++) {
        cin >> a >> b;
        cur-=a; cur+=b;
        maxx=max(cur,maxx);
    }
    cout << maxx << endl;
    return 0;
}
