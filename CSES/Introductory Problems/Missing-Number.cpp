#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, x;
int a[MAXN]={0};

int main() {
    cin >> n;
    while(cin >> x) {
        a[x]=1;
    }

    for(int i=1; i<=n; i++) {
        if(a[i]==0) {
            cout << i;
            break;
        }
    }
    return 0;
}