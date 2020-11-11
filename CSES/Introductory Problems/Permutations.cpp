#include <bits/stdc++.h>
using namespace std;
 
int n;
 
int main() {
    cin >> n;
    if(n==2 || n==3) cout << "NO SOLUTION" << endl;
    for(int i=2; i<=n; i+=2) cout << i << " ";
    for(int i=1; i<=n; i+=2) cout << i << " ";
    cout << endl;
    return 0;
}