#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n;
int a[MAXN];
long long res=0;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(i>0&&a[i]<a[i-1]) {
            int temp = a[i-1]-a[i];
            res+=temp;
            a[i]+=temp;
        }
    }

    cout << res << endl;
    return 0;
}