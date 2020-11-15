#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef long long ll;

int n;
int x[MAXN];
ll res=0;
ll maxx = INT_MIN, curr=0;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> x[i];
    for(int i=0; i<n; i++) {
        maxx = max(maxx,curr+x[i]);
        curr += x[i];
        if(curr<=0) curr = 0;
    }

    cout << maxx << endl;
    return 0;
}