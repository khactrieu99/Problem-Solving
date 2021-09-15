#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int main() {
    cin >> n;
    a.resize(n);
    for(auto &i: a) cin >> i;
    
    for(int i=0; i<(1<<n); i++) {
        int sum=0;
        for(int j=0; j<n; j++) { 
            if(i&(1<<j)) sum+=a[j];
            else sum-=a[j];
        }
        if(sum%360==0) {
            cout << "YES" << endl;
            return 0;
        }
    }   
    cout << "NO" << endl;

    return 0;
}
