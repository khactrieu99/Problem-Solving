#include <bits/stdc++.h>
using namespace std;

int n, i=4, ans=0;
int a[]={1, 5, 10 ,20, 100};
vector<int> dp;
int main() {
    cin >> n;
    while(n>0) {
        if(n>=a[i]) {
            ans+=n/a[i];
            n-=a[i]*(n/a[i]);
        }
        i--;
    }
    cout << ans << endl;
    return 0;
}
